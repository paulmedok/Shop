#pragma once
#include "BaseLoad.h"
#include "Tools.h"


class ToolsLoad :
	public BaseLoad
{
private:
	Tools *mpTool;

public:
	ToolsLoad();
	~ToolsLoad();

};

