#include "errors.h"
#include "..\parser.h"

Denisenko::Raskroy::t_parsed_cut
	convert(struct IParsedCut &Cut);

Denisenko::Raskroy::t_parsed_part
	convert(struct IParsedPart &Part);

Denisenko::Raskroy::t_parsed_cuts
	convert(struct IParsedCuts &Cuts);

Denisenko::Raskroy::t_parsed_parts
	convert(struct IParsedParts &Parts);

Denisenko::Raskroy::Stat
	convert(struct IStatistic &Statistic);

Denisenko::Raskroy::Part
	convert(struct ISheet &Sheet);

Denisenko::Raskroy::t_parts
	convert(struct ISheets &Sheets);

Denisenko::Raskroy::t_parsed_result
	convert(struct IResult &Result);

struct IParsedCut*
	convert(const Denisenko::Raskroy::t_parsed_cut&);

struct IParsedPart*
	convert(const Denisenko::Raskroy::t_parsed_part&);

struct IResult*
	convert(const Denisenko::Raskroy::t_parsed_result&);

Denisenko::Raskroy::t_parsed_result convert(BSTR str);