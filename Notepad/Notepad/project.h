#pragma once
#include<iostream>
#include "project.pb.h"
#include "versions.pb.h"

const char operationtypeDecode[3][10] = { "Add", "Remove", "Update" };

const int N = 5;

int toInt(std::string num);

class Projects {
private:
	std::string username;
	project::Project project1;
	project::ProjectNames projectslist;
	versions::Versions verSys;
	bool json;

	void updateLastModified();

	void revertAddLine();

	void revertUpdateLine();

	void revertRemoveLine();

	void addVersion();

	void revertLastVersion();

public:
	Projects(std::string, bool); 

	bool openProject();

	void writeProject();
	
	void createNewProject();
	
	void deleteProject(std::string id );
	
	void deleteAllProject();
	
	void printAllProjectsInfo();
	
	void printProjectInfo();
	
	void addLine();
	
	void printText();
	
	void updateLine();
	
	void removeLine();
	
	void revertLastChange();
	
	void printChanges();

	void printVersions();
	
	void revertbackVersion();

};