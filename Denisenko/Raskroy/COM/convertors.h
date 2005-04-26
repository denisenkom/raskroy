#include "errors.h"

raskroy::t_parsed_cut
	convert(struct IParsedCut &Cut);

raskroy::t_parsed_part
	convert(struct IParsedPart &Part);

raskroy::t_parsed_cuts
	convert(struct IParsedCuts &Cuts);

raskroy::t_parsed_parts
	convert(struct IParsedParts &Parts);

raskroy::t_stat
	convert(struct IStatistic &Statistic);

raskroy::t_part
	convert(struct ISheet &Sheet);

raskroy::t_parts
	convert(struct ISheets &Sheets);

raskroy::t_parsed_result
	convert(struct IResult &Result);

struct IParsedCut*
	convert(const raskroy::t_parsed_cut&);

struct IParsedPart*
	convert(const raskroy::t_parsed_part&);

struct IResult*
	convert(const raskroy::t_parsed_result&);

raskroy::t_parsed_result convert(BSTR str);