using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace Denisenko.Cutting.CutOptima
{
	static class Program
	{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			AppDomain.CurrentDomain.UnhandledException += UnhandledExceptionHandler;
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Application.Run(MainForm.Instance);
		}

		static void UnhandledExceptionHandler(Object sender, UnhandledExceptionEventArgs args)
		{
			StringWriter writer = new StringWriter();
			writer.WriteLine("Unhandled exception report.");
			writer.WriteLine("Date-time: {0}", DateTime.Now);
			writer.WriteLine("Machine name: {0}", Environment.MachineName);
			writer.WriteLine("OS version: {0}", Environment.OSVersion);
			writer.WriteLine("Stack trace:");
			writer.WriteLine(args.ExceptionObject.ToString());
			writer.WriteLine("END OF REPORT");
			writer.WriteLine();
			ThreadPool.QueueUserWorkItem(WriteUnhandledExcReportToServer, writer.ToString());
		}

		static void WriteUnhandledExcReportToServer(Object state)
		{
			try
			{
				String report = (String)state;
				using (StreamWriter stream =
					new StreamWriter(
						@"\\192.168.0.1\DeveloperPortal\CutOptima\unhandledException.txt",
						true, Encoding.Unicode))
				{
					stream.WriteLine(report);
				}
			}
			catch
			{
			}
		}
	}
}