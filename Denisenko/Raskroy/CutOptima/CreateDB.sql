SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[Materials](
	[MaterialID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) COLLATE Cyrillic_General_CI_AS NOT NULL,
	[HaveDirection] [bit] NOT NULL,
	[Remarks] [text] COLLATE Cyrillic_General_CI_AS NULL,
 CONSTRAINT [PK_Materials] PRIMARY KEY CLUSTERED 
(
	[MaterialID] ASC
)
)

GO
CREATE TABLE [dbo].[DetailsLists](
	[DetailsListID] [int] IDENTITY(1,1) NOT NULL,
	[OrderID] [nvarchar](50) COLLATE Cyrillic_General_CI_AS NULL,
	[Remarks] [nvarchar](100) COLLATE Cyrillic_General_CI_AS NULL,
 CONSTRAINT [PK_DetailsLists] PRIMARY KEY CLUSTERED 
(
	[DetailsListID] ASC
)
)

GO
CREATE TABLE [dbo].[CuttingResults](
	[CuttingResultID] [int] IDENTITY(1,1) NOT NULL,
	[Data] [binary](300) NULL,
 CONSTRAINT [PK_CuttingResults] PRIMARY KEY CLUSTERED 
(
	[CuttingResultID] ASC
)
)

GO
CREATE TABLE [dbo].[CuttingParameters](
	[CuttingParametersID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) COLLATE Cyrillic_General_CI_AS NOT NULL,
	[CutterThickness] [decimal](18, 3) NOT NULL,
	[TopCutOff] [decimal](18, 3) NOT NULL,
	[LeftCutOff] [decimal](18, 3) NOT NULL,
	[RightCutOff] [decimal](18, 3) NOT NULL,
	[BottomCutOff] [decimal](18, 3) NOT NULL,
 CONSTRAINT [PK_CuttingParameters] PRIMARY KEY CLUSTERED 
(
	[CuttingParametersID] ASC
)
)

GO
CREATE TABLE [dbo].[PartProperties](
	[PropertyID] [nvarchar](30) COLLATE Cyrillic_General_CI_AS NOT NULL,
	[Description] [ntext] COLLATE Cyrillic_General_CI_AS NULL,
 CONSTRAINT [PK_PartProperties] PRIMARY KEY CLUSTERED 
(
	[PropertyID] ASC
)
)

GO
CREATE TABLE [dbo].[ReferenceParts](
	[ReferencePartID] [int] NOT NULL,
	[Name] [nvarchar](50) COLLATE Cyrillic_General_CI_AS NOT NULL,
	[Length] [decimal](18, 3) NOT NULL,
	[Width] [decimal](18, 3) NOT NULL,
	[Material] [nvarchar](50) COLLATE Cyrillic_General_CI_AS NULL,
 CONSTRAINT [PK_ReferenceDetails] PRIMARY KEY CLUSTERED 
(
	[ReferencePartID] ASC
)
)

GO
CREATE TABLE [dbo].[Sheets](
	[SheetID] [int] IDENTITY(1,1) NOT NULL,
	[Name] [nvarchar](50) COLLATE Cyrillic_General_CI_AS NULL,
	[Length] [decimal](18, 3) NOT NULL,
	[Width] [decimal](18, 3) NOT NULL,
	[MaterialID] [int] NOT NULL,
 CONSTRAINT [PK_Sheets] PRIMARY KEY CLUSTERED 
(
	[SheetID] ASC
)
)

GO
CREATE TABLE [dbo].[DetailsListsDetails](
	[DetailsListsDetailID] [int] IDENTITY(1,1) NOT NULL,
	[DetailsListID] [int] NOT NULL,
	[Name] [nvarchar](50) COLLATE Cyrillic_General_CI_AS NOT NULL,
	[Length] [decimal](18, 3) NOT NULL,
	[Width] [decimal](18, 3) NOT NULL,
	[Amount] [int] NOT NULL,
	[MaterialID] [int] NOT NULL,
	[LeftEdge] [nchar](10) COLLATE Cyrillic_General_CI_AS NULL,
	[TopEdge] [nchar](10) COLLATE Cyrillic_General_CI_AS NULL,
	[RightEdge] [nchar](10) COLLATE Cyrillic_General_CI_AS NULL,
	[BottomEdge] [nchar](10) COLLATE Cyrillic_General_CI_AS NULL,
 CONSTRAINT [PK_DetailsListsDetails] PRIMARY KEY CLUSTERED 
(
	[DetailsListsDetailID] ASC
)
)

GO
ALTER TABLE [dbo].[Sheets]  WITH CHECK ADD  CONSTRAINT [FK_Sheets_Materials] FOREIGN KEY([MaterialID])
REFERENCES [dbo].[Materials] ([MaterialID])
GO
ALTER TABLE [dbo].[DetailsListsDetails]  WITH NOCHECK ADD  CONSTRAINT [FK_DetailsListsDetails_DetailsLists] FOREIGN KEY([DetailsListID])
REFERENCES [dbo].[DetailsLists] ([DetailsListID])
ON DELETE CASCADE
GO
ALTER TABLE [dbo].[DetailsListsDetails] CHECK CONSTRAINT [FK_DetailsListsDetails_DetailsLists]
GO
ALTER TABLE [dbo].[DetailsListsDetails]  WITH NOCHECK ADD  CONSTRAINT [FK_DetailsListsDetails_Materials] FOREIGN KEY([MaterialID])
REFERENCES [dbo].[Materials] ([MaterialID])
GO
ALTER TABLE [dbo].[DetailsListsDetails] CHECK CONSTRAINT [FK_DetailsListsDetails_Materials]
