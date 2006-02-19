namespace Denisenko.Cutting.CutOptima.CuttingWizard {


	partial class DataSet
	{
		public static void AssignDetailsListRow(DetailsListsRow sourceRow, DetailsListsRow destRow)
		{
			destRow.DetailsListID = sourceRow.DetailsListID;
			if (sourceRow.IsOrderIDNull())
				destRow.SetOrderIDNull();
			else
				destRow.OrderID = sourceRow.OrderID;
			if (sourceRow.IsRemarksNull())
				destRow.SetRemarksNull();
			else
				destRow.Remarks = sourceRow.Remarks;
		}
    }
}
