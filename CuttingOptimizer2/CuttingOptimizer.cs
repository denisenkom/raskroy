using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;


namespace Denisenko.Cutting.Optimizing {
    using Scalar = Int64;

    public enum ElementType
    {
        Remain = 0,
        Cut = 1,
        Rect = 2,
        SubLayout = 3,
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct _LayoutRect
    {
        public Scalar size_x;
        public Scalar size_y;
        public Int32 can_rotate;
        public UInt32 amount;
    }

    [StructLayout(LayoutKind.Explicit)]
    unsafe public struct _LayoutElement
    {
        [FieldOffset(0)]
        public Scalar size;
        [FieldOffset(8)]
        public Int32 type;
        [FieldOffset(16)]
        public _Layout * layout;
        [FieldOffset(16)]
        public Int32 rect_index;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct _Layout
    {
        public Int32 along;
        public UIntPtr num_elements;
        unsafe public _LayoutElement * elements;
    }


    public class _GuillotineApi
    {
        [DllImport("guillotine_interop.dll")]
        unsafe public static extern Int32 new_layout2d(
            _LayoutRect* rects, UInt32 num,
            Scalar sheet_x, Scalar sheet_y, Scalar cut_size,
            _Layout ** result);

        [DllImport("guillotine_interop.dll")]
        unsafe public static extern void free_layout(_Layout * layout);

        public static Decimal FromScaled(Int64 scaled)
        {
	        return (decimal)scaled / 1000;
        }

        public static Int64 ToScaled(Decimal value)
        {
	        return decimal.ToInt64(value * 1000);
        }

	    unsafe public static CuttingScheme ConvertLayout(_Layout * layout, ParametersCollection parameters, Sheet sheet)
	    {
		    CuttingScheme result = new CuttingScheme();
            result.Sheet = sheet;
            result.Parameters = parameters;
		    CuttingResultBuilder builder = new CuttingResultBuilder();
		    builder.LoadSections(layout, result);
		    return result;
	    }
    }


	public class CannotCutDetailsException : Exception
	{
	public CannotCutDetailsException(String message)
			: base(message)
		{
		}
	};


	public class Optimizer
	{
		public Optimizer()
		{
			//m_started = false;
			m_parts = new List<Part>();
			m_sheets = new List<Sheet>();
			m_parameters = new ParametersCollection();
		}

		public List<Part> Parts { get { return m_parts; } }
		public List<Sheet> Sheets { get { return m_sheets; } }
		public ParametersCollection Parameters { get { return m_parameters; } }
		public CuttingScheme CurrentResult { get { return m_result; } }
		public Single PercentCompleted { get { return 0; } } // thread safe

		/*public void Reset()
		{
			m_started = false;
		}*/

        public CuttingScheme Layout2d(List<Part> parts, Sheet sheet, Decimal cut_size)
        {
            unsafe
            {
                var rects = (_LayoutRect*)Marshal.AllocHGlobal(Marshal.SizeOf(typeof(_LayoutRect)) * parts.Count);
                try
                {
                    for (var i = 0; i < parts.Count; i++)
                    {
                        rects[i].amount = (uint)parts[i].Quantity;
                        rects[i].can_rotate = parts[i].CanRotate ? 1 : 0;
                        rects[i].size_x = _GuillotineApi.ToScaled(parts[i].Length);
                        rects[i].size_y = _GuillotineApi.ToScaled(parts[i].Width);
                    }
                    _Layout* layout;
                    var ret = _GuillotineApi.new_layout2d(rects, (uint)parts.Count,
                        _GuillotineApi.ToScaled(sheet.Width - Parameters.CutOffLeft - Parameters.CutOffRight),
                        _GuillotineApi.ToScaled(sheet.Height - Parameters.CutOffTop - Parameters.CutOffBottom),
                        _GuillotineApi.ToScaled(cut_size), &layout);

                    try
                    {
                        if (ret == 0)
                        {
                            return null;
                        }
                        else
                        {
                            var scheme = _GuillotineApi.ConvertLayout(layout, m_parameters, sheet);
                            for (var i = 0; i < parts.Count; i++)
                            {
                                parts[i].Quantity = (int)rects[i].amount;
                            }
                            return scheme;
                        }
                    }
                    finally
                    {
                        _GuillotineApi.free_layout(layout);
                    }
                }
                finally
                {
                    Marshal.FreeHGlobal((IntPtr)rects);
                }
            }
        }

		public Boolean NextResult() 
		{
            //m_started = true;
            if (m_parts.Count == 0)
                throw new CannotCutDetailsException("Нельзя расположить детали, список деталей не заполнен.");
            if (m_sheets.Count == 0)
                throw new CannotCutDetailsException("Нельзя расположить детали, список листов не заполнен.");
            CuttingScheme best_result = null;
            foreach (var sheet in m_sheets)
            {
                var result = Layout2d(m_parts, sheet, Parameters.CutterThickness);
                if (object.ReferenceEquals(best_result, null))
                {
                    best_result = result;
                }
                else
                {
                    if (result.BetterThan(best_result))
                        best_result = result;
                }
            }
            m_result = best_result;
            return !object.ReferenceEquals(best_result, null);
		}

		private List<Part> m_parts;
		private List<Sheet> m_sheets;
		//private Boolean m_started;
		private ParametersCollection m_parameters;
		private CuttingScheme m_result;
	};
}