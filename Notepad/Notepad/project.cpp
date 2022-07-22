#include <iostream>
#include <fstream>
#include <time.h>
#include <direct.h>
#include <vector>
#include "project.pb.h"
#include "versions.pb.h"
#include "project.h"
#pragma warning(disable : 4996)

int toInt(std::string num)
{
	int res = 0;
	for (int i = 0; i < num.size(); i++)
	{
		if (isdigit(num[i])) res += ((int)num[i] - 48) * pow(10, num.size() - 1 - i);

		else return -1;
	}
	return res;
}

Projects::Projects(std::string username) {
	this->username = username;
	std::ifstream fin;
	_mkdir("projects");
	system("cd");
	fin.open("projects/projectheaders.bin", std::ios::in | std::ios::binary);
	if (!this->projectslist.ParseFromIstream(&fin)) {
		std::cout << "Failed to parse address book. " << std::endl;
	}
	fin.close();
}

bool Projects::openProject() {

	std::string id;
	std::cout << "Enter the id of project to open: " << std::endl;
	std::cin >> id;
	for (int i = 0; i < this->projectslist.projectnames_size(); i++) {
		if (id == projectslist.projectnames(i).id()) {
			if (this->username == projectslist.projectnames(i).author()) {
				std::ifstream fin;

				fin.open("./projects/" + id + "_" + projectslist.projectnames(i).name() + "/project.bin", std::ios::in | std::ios::binary);
				if (!(this->project1.ParseFromIstream(&fin))) {
					std::cout << "Failed to parse project file. " << std::endl;
				}
				std::cout << this->project1.author() << this->project1.createdtime();
				fin.close();

				fin.open("./projects/" + id + "_" + projectslist.projectnames(i).name() + "/vcs.bin", std::ios::in | std::ios::binary);
				if (!(this->verSys.ParseFromIstream(&fin))) {
					std::cout << "Failed to parse changes/version file. " << std::endl;
				}
				fin.close();

				return true;
			}
			else {
				std::cout << "Not authorized to access this project";
				return false;
			}
		}
		if (i == this->projectslist.projectnames_size() - 1) {
			std::cout << "Invalid Project Id";
			return false;
		}
	}
}

void Projects::writeProject() {
	std::ofstream fout;
	std::cout << "writing output";
	std::string  id, name;
	id = project1.id();
	name = project1.name();
	fout.open("./projects/" + id + "_" + name + "/project.bin", std::ios::out | std::ios::binary);
	if (!this->project1.SerializeToOstream(&fout)) {
		std::cout << "Failed to write address book." << std::endl;
	}
	fout.close();

	fout.open("./projects/" + id + "_" + name + "/vcs.bin", std::ios::out | std::ios::binary);
	if (!this->verSys.SerializeToOstream(&fout)) {
		std::cout << "Failed to write changes/version." << std::endl;
	}
	fout.close();
}

void Projects::createNewProject() {
	std::string name, id;
	project::ProjectHeader* newProject = this->projectslist.add_projectnames();

	newProject->set_author(this->username);

	std::cout << "Enter the project name: ";
	std::cin >> name;
	newProject->set_name(name);

	id = std::to_string(this->projectslist.counter());
	this->projectslist.set_counter(this->projectslist.counter() + 1);
	newProject->set_id(id);


	time_t my_time = time(NULL);
	newProject->set_creationdate(ctime(&my_time));

	std::ofstream fout;
	fout.open("projects/projectheaders.bin", std::ios::out | std::ios::binary);
	if (!this->projectslist.SerializeToOstream(&fout))
		std::cout << "Unable to write data" << std::endl;
	fout.close();


	project::Project p1 = project::Project();
	p1.set_id(id);
	p1.set_name(name);
	p1.set_author(this->username);
	p1.set_createdtime(ctime(&my_time));
	p1.set_lastmodified(ctime(&my_time));

	std::string ud = "_";
	_chdir("projects");
	_mkdir(&(id + ud + name)[0]);
	fout.open(id + ud + name + "/" + "project.bin", std::ios::out | std::ios::binary);

	if (!p1.SerializeToOstream(&fout))
		std::cout << "Unable to write data";
	fout.close();
	_chdir("..");
}

void Projects::printProjectInfo() {

	std::cout << std::endl;
	std::cout << "PROJECT INFO " << std::endl;
	std::cout << "Project ID: " << this->project1.id() << std::endl;
	std::cout << "Name :" << this->project1.name() << std::endl;
	std::cout << "Creation Date: " << this->project1.createdtime() << std::endl;
	std::cout << "Last Modified: " << this->project1.lastmodified() << std::endl;
	std::cout << "Version: " << this->project1.version() << std::endl;
	std::cout << "Number of Operations perfomed: " << this->project1.operationscount() << std::endl;
}

void Projects::printAllProjectsInfo() {

	for (int i = 0; i < this->projectslist.projectnames_size(); i++) {
		const project::ProjectHeader& projecti = this->projectslist.projectnames(i);
		if (projecti.author() == this->username)
			std::cout << projecti.id() << "_" << projecti.name() << std::endl;
	}
}

void Projects::deleteProject(std::string id) {
	for (int i = 0; i < this->projectslist.projectnames_size(); i++) {
		if (id == projectslist.projectnames(i).id() && this->username == projectslist.projectnames(i).author()) {
			auto a = this->projectslist.mutable_projectnames();
			system(&("rd /s /q projects\\" + id + "_" + this->projectslist.projectnames(i).name())[0]);
			//a->SwapElements(i, projectslist.projectnames_size() - 1);
			//a->RemoveLast();
			while (i < projectslist.projectnames_size() - 1) {
				a->SwapElements(i, i + 1);
				i++;
			}
			a->RemoveLast();
		}
	}
	std::ofstream fout;
	fout.open("projects/projectheaders.bin", std::ios::out | std::ios::binary);
	if (!this->projectslist.SerializeToOstream(&fout))
		std::cout << "Unable to write data";
	fout.close();
}

void Projects::deleteAllProject() {
	int i = 0;
	while (i < this->projectslist.projectnames_size()) {
		std::cout << this->projectslist.projectnames(i).id() << std::endl;
		deleteProject(this->projectslist.projectnames(i).id());
	}
}

void Projects::addLine() {
	std::string line;
	std::cout << "enter the line to be added at last: ";
	std::cin.ignore();
	std::getline(std::cin, line);
	std::string* a = this->project1.add_text();
	*a = line;
	this->project1.set_operationscount(this->project1.operationscount() + 1);
	auto* change = this->verSys.add_changes();
	change->set_opearationtype(versions::ADD);
	change->set_linenum(this->project1.text_size());
	change->set_line0(this->project1.text(this->project1.text_size() - 1));
	time_t my_time = time(NULL);
	change->set_timestamp(ctime(&my_time));

	updateLastModified();
	this->addVersion();
}

void Projects::printText() {
	for (int i = 0; i < project1.text_size(); i++) {
		std::cout << i + 1 << "  " << project1.text(i) << std::endl;
	}
	std::cout << this->project1.lastmodified();
}

void Projects::updateLine() {
	if (this->project1.text_size()) {
		int ln;
		std::string updatedLine,lns;
		std::cout << "Enter the line number to be updated: ";
		std::cin >> lns;
		ln = toInt(lns);
		if (ln == -1) {
			std::cout << "Invalid number " << std::endl;
			return;
		}
			std::cout << " Enter the text: ";
		std::cin.ignore();
		std::getline(std::cin, updatedLine);
		std::string prev = this->project1.text(ln - 1);
		project1.set_text(ln - 1, updatedLine);
		this->project1.set_operationscount(this->project1.operationscount() + 1);

		auto* change = this->verSys.add_changes();

		change->set_opearationtype(versions::UPDATE);
		change->set_linenum(ln);
		change->set_line0(prev);
		change->set_line1(project1.text(ln - 1));
		time_t my_time = time(NULL);
		change->set_timestamp(ctime(&my_time));


		updateLastModified();
		this->addVersion();
	}
	else {
		std::cout << "No lines in the text";
	}
}

void Projects::removeLine() {
	if (this->project1.text_size()) {
		int ln;
		std::string lns;
		std::cout << "Enter the line number to be removed: ";
		std::cin.ignore();
		std::cin >> lns;
		ln = toInt(lns);
		if (ln == -1) {
			std::cout << "Invalid number " << std::endl;
			return;
		}
		auto* change = this->verSys.add_changes();


		change->set_opearationtype(versions::DELETE);
		change->set_linenum(ln);
		change->set_line0(this->project1.text(ln - 1));


		auto* a = this->project1.mutable_text();
		while (ln < this->project1.text_size()) {
			a->SwapElements(ln - 1, ln);
			ln++;
		}
		this->project1.set_operationscount(this->project1.operationscount() + 1);

		a->RemoveLast();
		time_t my_time = time(NULL);
		change->set_timestamp(ctime(&my_time));

		updateLastModified();
		this->addVersion();
	}
	else {
		std::cout << "No lines in the text";
	}
}

void Projects::updateLastModified() {
	time_t my_time = time(NULL);
	this->project1.set_lastmodified(ctime(&my_time));
}

void Projects::revertAddLine() {
	auto change = this->verSys.changes(this->verSys.changes_size() - 1);
	auto text = project1.mutable_text();
	text->RemoveLast();
	std::string timestampPrev = verSys.changes_size() > 1 ? verSys.changes(verSys.changes_size() - 2).timestamp() :
		(this->verSys.versionlist_size() > 0 ? this->verSys.versionlist(this->verSys.versionlist_size() - 1).createdtime() : this->project1.createdtime());
	this->project1.set_lastmodified(timestampPrev);


	auto changes = verSys.mutable_changes();
	changes->RemoveLast();

}

void Projects::revertUpdateLine() {
	auto change = this->verSys.changes(this->verSys.changes_size() - 1);
	std::string prevLine = change.line0();
	this->project1.set_text(change.linenum() - 1, prevLine);
	std::string timestampPrev = verSys.changes_size() > 1 ? verSys.changes(verSys.changes_size() - 2).timestamp() :
		(this->verSys.versionlist_size() > 0 ? this->verSys.versionlist(this->verSys.versionlist_size() - 1).createdtime() : this->project1.createdtime());
	this->project1.set_lastmodified(timestampPrev);

	auto changes = this->verSys.mutable_changes();
	changes->RemoveLast();
}

void Projects::revertRemoveLine() {
	auto change = this->verSys.changes(this->verSys.changes_size() - 1);
	this->project1.add_text();
	auto a = project1.mutable_text();
	int i = project1.text_size() - 1;
	while (i >= change.linenum()) {
		a->SwapElements(i - 1, i);
		i--;
	}
	this->project1.set_text(change.linenum() - 1, change.line0());
	std::string timestampPrev = verSys.changes_size() > 1 ? verSys.changes(verSys.changes_size() - 2).timestamp() :
		(this->verSys.versionlist_size() > 0 ? this->verSys.versionlist(this->verSys.versionlist_size() - 1).createdtime() : this->project1.createdtime());
	this->project1.set_lastmodified(timestampPrev);

	auto changes = verSys.mutable_changes();
	changes->RemoveLast();

}

void Projects::revertLastChange() {
	if (this->verSys.changes_size()) {
		auto change = this->verSys.changes(this->verSys.changes_size() - 1);
		switch (change.opearationtype())
		{
		case versions::ADD:
			this->revertAddLine();
			break;
		case versions::DELETE:
			this->revertRemoveLine();
			break;
		case versions::UPDATE:
			this->revertUpdateLine();
			break;
		default:
			std::cout << "Error occured in decoding operation type" << std::endl;
		}
		this->project1.set_operationscount(this->project1.operationscount() - 1);
	}
	else
		std::cout << "No changes available";
}

void Projects::printChanges() {
	for (int i = 0; i < verSys.changes_size(); i++) {
		std::cout << "Operation Type: " << operationtypeDecode[verSys.changes(i).opearationtype()] << std::endl;
		std::cout << "Line number: " << verSys.changes(i).linenum() << std::endl;
		std::cout << "contents modified: " << verSys.changes(i).line0() << std::endl;
		std::cout << verSys.changes(i).line1() << std::endl;
		std::cout << "Time stamp: " << verSys.changes(i).timestamp() << std::endl;
		std::cout << std::endl;
	}
}

void Projects::addVersion() {
	if ((project1.operationscount() % N) == 0) {
		auto newVersion = this->verSys.add_versionlist();
		for (int i = 0; i < N; i++) {
			auto newChange = newVersion->add_changes();
			newChange->CopyFrom(this->verSys.changes(this->verSys.changes_size() - N + i));
		}


		newVersion->set_versionnumber(this->project1.version());
		this->project1.set_version(this->project1.version() + 1);

		auto mutchanges = this->verSys.mutable_changes();
		for (int i = 0; i < N; i++) {
			mutchanges->RemoveLast();
		}
		time_t my_time = time(NULL);
		newVersion->set_createdtime(ctime(&my_time));

		std::ofstream fout;
		fout.open("./projects/" + project1.id() + "_" + project1.name() + "/vcs.bin", std::ios::out | std::ios::binary);
		if (!this->verSys.SerializeToOstream(&fout)) {
			std::cout << "Failed to write changes/version." << std::endl;
		}
		fout.close();

	}
}

void Projects::printVersions() {
	for (int i = 0; i < this->verSys.versionlist_size(); i++) {
		std::cout << this->verSys.versionlist(i).versionnumber() << std::endl;
		std::cout << this->verSys.versionlist(i).createdtime() << std::endl;
	}
}

void Projects::revertLastVersion() {
	if (this->verSys.versionlist_size()) {
		const versions::Version lastVersion = this->verSys.versionlist(this->verSys.versionlist_size() - 1);
		auto lastVersionMutable = this->verSys.mutable_versionlist(this->verSys.versionlist_size() - 1);
		auto lastVersionChanges = lastVersionMutable->mutable_changes();

		int i = 0;
		while (i < lastVersion.changes_size()) {
			auto change = this->verSys.add_changes();
			change->CopyFrom(lastVersion.changes(i));
			i++;
		}

		auto versionlistMutable = verSys.mutable_versionlist();
		versionlistMutable->RemoveLast();

		while (verSys.changes_size()) {
			this->revertLastChange();
		}
		//this->project1.set_lastmodified(lastVersion.createdtime());
		this->project1.set_version(lastVersion.versionnumber());

	}
	else
		std::cout << "versions not available";
}

void Projects::revertbackVersion() {
	int32_t versionNum;
	std::cout << "Enter the version number to revert back";
	std::cin >> versionNum;
	bool present = false;
	for (int i = 0; i < this->verSys.versionlist_size(); i++) {
		if (this->verSys.versionlist(i).versionnumber() == versionNum) {
			present = true;
			break;
		}
	}
	if (!present) {
		std::cout << "invalid version number" << std::endl;
		return;
	}

	while (this->verSys.changes_size()) {
		this->revertLastChange();
	}
	while (this->project1.version() != versionNum) {
		this->revertLastVersion();
	}
}
