#ifndef GCStatsLUGIN_H
#define GCStatsPLUGIN_H

#include "Plugin.h"
#include "Tool.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class GCStatsPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "GCStats";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
