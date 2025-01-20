#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "GCStatsPlugin.h"

void GCStatsPlugin::input(std::string file) {
 inputfile = file;
 readParameterFile(inputfile);
}

void GCStatsPlugin::run() {
   
}

void GCStatsPlugin::output(std::string file) {
 // alpha_diversity.py -i filtered_otu_table.biom -m observed_species,chao1,shannon,PD_whole_tree -t rep_set.tre -o alpha.txt
   //std::string command = "samtools sort " + inputfile + " > "+file;
	std::string command = "";

command = "echo -e \"contig\\tread_GC_ont\" > "+file;
	std::cout << command << std::endl;
        system(command.c_str());

command = "while read -r line; do ";
	/*std::cout << command << std::endl;
        system(command.c_str());*/

command += "gc_number=$(awk 'NR%4 == 2 {print}' "+PluginManager::addPrefix(myParameters["fastqdir"])+"/\"${line}\".fastq | awk '{count += gsub(/[gcGC]/, \"\");} END {print count}'); ";
	/*std::cout << command << std::endl;
        system(command.c_str());*/

command += "total_bases=$(awk 'NR%4 == 2 {print}' "+PluginManager::addPrefix(myParameters["fastqdir"])+"/\"${line}\".fastq | tr -d '\\n' | wc -c); ";
	/*std::cout << command << std::endl;
        system(command.c_str());*/

command += "gc_percent=$(awk -v total=\"$total_bases\" -v value=\"$gc_number\" 'BEGIN { printf((value/total)*100); }'); ";
	/*std::cout << command << std::endl;
        system(command.c_str());*/

command += "echo -e \"$line\\t$gc_percent\" >> "+file+"; ";
	/*std::cout << command << std::endl;
        system(command.c_str());*/

command += "done < "+PluginManager::addPrefix(myParameters["contigs"]);
	std::cout << command << std::endl;
        system(command.c_str());
}

PluginProxy<GCStatsPlugin> GCStatsPluginProxy = PluginProxy<GCStatsPlugin>("GCStats", PluginManager::getInstance());
