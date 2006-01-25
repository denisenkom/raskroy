using System;
using System.Collections.Generic;
using System.Text;

namespace Denisenko.Cutting.CutOptima
{
	class Mediator
	{
		private static Mediator m_instance;

		public static Mediator Instance 
		{
			get 
			{
				if (m_instance == null)
					m_instance = new Mediator();
				return m_instance;
			} 
		}

		public void OpenReferenceDetails()
		{
			ReferenceDetailsForm.Instance.MdiParent = MainForm.Instance;
			ReferenceDetailsForm.Instance.Show();
		}

		public void OpenListsEditor()
		{
			DetailsListsForm.Instance.MdiParent = MainForm.Instance;
			DetailsListsForm.Instance.Show();
		}

		public void OpenListEditor(Int32 listID)
		{
			DetailsListForm editor = new DetailsListForm();
			editor.MdiParent = MainForm.Instance;
			editor.Show();
		}
	}
}
