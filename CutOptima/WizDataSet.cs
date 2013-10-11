namespace Denisenko.Cutting.CutOptima
{
    public partial class WizDataSet
	{
		public static void AssignDetailsListRow(WizDetailsListsRow sourceRow, WizDetailsListsRow destRow)
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
