using System;
using System.Collections.Generic;
using System.Text;
using System.Data.SqlClient;
using System.Threading;

using Denisenko.Cutting.Optimizing;
using Denisenko.Cutting.Optimizing.DataSetTableAdapters;

namespace Denisenko.Cutting.Optimizing
{
	public enum StatusType
	{
		Completed,
		Error,
		Canceled,
	}

	public class OptimizingJob
	{
		private Thread _worker;
		private DataSet _dataSet;
		private List<CuttingScheme> _schemes;
		private Boolean _canceled = false;
		private Optimizer _optimizer;
		private StatusType _status;
		private CannotCutDetailsException _error;

		public StatusType Status
		{
			get { return _status; }
		}

		public CannotCutDetailsException Error
		{
			get { return _error; }
		}

		public OptimizingJob()
		{
			_schemes = new List<CuttingScheme>();
			_dataSet = new DataSet();
		}

		public void Load(String connectionString, Int32[] partsListsIds, Int32[] sheetsIds)
		{
			SqlConnection connection = new SqlConnection(connectionString);
			
			DetailsListsTableAdapter detailsListsAdapter = new DetailsListsTableAdapter();
			DetailsListsDetailsTableAdapter detailsByListsAdapter = new DetailsListsDetailsTableAdapter();
			MaterialsTableAdapter materialsAdapter = new MaterialsTableAdapter();
			SheetsTableAdapter sheetsAdapter = new SheetsTableAdapter();

			detailsListsAdapter.Connection = connection;
			detailsByListsAdapter.Connection = connection;
			materialsAdapter.Connection = connection;
			sheetsAdapter.Connection = connection;

			_dataSet.DetailsLists.Clear();
			_dataSet.DetailsListsDetails.Clear();
			foreach (Int32 partsListID in partsListsIds)
			{
				_dataSet.DetailsLists.Merge(detailsListsAdapter.GetDataBy(partsListID));
				_dataSet.DetailsListsDetails.Merge(detailsByListsAdapter.GetDataBy(partsListID));
			}
			materialsAdapter.Fill(_dataSet.Materials);
			_dataSet.Sheets.Clear();
			foreach (Int32 sheetID in sheetsIds)
			{
				_dataSet.Sheets.Merge(sheetsAdapter.GetDataBy(sheetID));
			}
		}

		public void Load(String connectionString, Int32[] partsListsIds)
		{
			SqlConnection connection = null;
			try
			{
				connection = new SqlConnection(connectionString);

				DetailsListsTableAdapter detailsListsAdapter = new DetailsListsTableAdapter();
				DetailsListsDetailsTableAdapter detailsByListsAdapter = new DetailsListsDetailsTableAdapter();
				MaterialsTableAdapter materialsAdapter = new MaterialsTableAdapter();
				SheetsTableAdapter sheetsAdapter = new SheetsTableAdapter();

				detailsListsAdapter.Connection = connection;
				detailsByListsAdapter.Connection = connection;
				materialsAdapter.Connection = connection;
				sheetsAdapter.Connection = connection;

				_dataSet.DetailsLists.Clear();
				_dataSet.DetailsListsDetails.Clear();
				foreach (Int32 partsListID in partsListsIds)
				{
					_dataSet.DetailsLists.Merge(detailsListsAdapter.GetDataBy(partsListID));
					_dataSet.DetailsListsDetails.Merge(detailsByListsAdapter.GetDataBy(partsListID));
				}
				materialsAdapter.Fill(_dataSet.Materials);
				sheetsAdapter.Fill(_dataSet.Sheets);

			}
			finally
			{
				if (connection != null) connection.Close();
			}
		}

		public void AsyncExecute()
		{
			_worker = new Thread(SyncExecute);
			_worker.Start();
		}

		public void SyncExecute()
		{
			try
			{
				foreach (DataSet.MaterialsRow materialRow in _dataSet.Materials.Rows)
				{
                    _optimizer = new Optimizer();
					foreach (DataSet.DetailsListsDetailsRow row in materialRow.GetDetailsListsDetailsRows())
					{
						Part part = new Part();
						part.Length = row.Length;
						part.Width = row.Width;
						part.Quantity = row.Amount;
						part.CanRotate = !row.MaterialsRow.HaveDirection;
						_optimizer.Parts.Add(part);
					}
					foreach (DataSet.SheetsRow row in materialRow.GetSheetsRows())
					{
						Sheet sheet = new Sheet();
						sheet.Width = row.Length;
						sheet.Height = row.Width;
						// TODO: добавить в схему БД поле Толщина для листов
						//sheet.Thickness = row.Thickness;
						sheet.Thickness = 16M;
						_optimizer.Sheets.Add(sheet);
					}
					while (_optimizer.NextResult())
					{
						_optimizer.CurrentResult.Material = new Material(materialRow.MaterialID, materialRow.Name, !materialRow.HaveDirection);
						_schemes.Add(_optimizer.CurrentResult);
					}
				}
				_status = StatusType.Completed;
			}
			catch (CannotCutDetailsException ex)
			{
				_status = StatusType.Error;
				_error = ex;
			}
		}

		public void Join()
		{
			_worker.Join();
		}

		public bool Join(int millisecondsTimeout)
		{
			return _worker.Join(millisecondsTimeout);
		}

		public void Cancel()
		{
			_worker.Abort();
			_status = StatusType.Canceled;
		}

		public List<CuttingScheme> Result
		{
			get
			{
				return _schemes;
			}
		}

		public Single PercentCompleted
		{
			get
			{
				if (_optimizer != null)
				{
					return _optimizer.PercentCompleted;
				}
				else
				{
					return 0;
				}
			}
		}
	}
}
