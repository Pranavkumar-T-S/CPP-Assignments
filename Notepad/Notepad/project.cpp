#include <iostream>
#include <fstream>
#include <time.h>
#include <direct.h>
#include "project.pb.h"
#pragma warning(disable : 4996)

class Projects {
private:
	std::string username;
	project::Project project1;
	project::ProjectNames projectslist;

public:
	Projects(std::string username) {
		this->username = username;
		std::ifstream fin;
		_mkdir("projects");
		system("cd");
		fin.open("projects/projectheaders.bin", std::ios_base::binary);
		if (!this->projectslist.ParseFromIstream(&fin)) {
			std::cout << "Failed to peffearse a23ddress boodk. " << std::endl;
		}
		fin.close();
	}

	void openProject() {

		std::string id;
		std::cout << "Enter the id of project to open: " << std::endl;
		std::cin >> id;
		for (int i = 0; i < this->projectslist.projectnames_size(); i++) {
			if (id == projectslist.projectnames(i).id()) {
				if (this->username == projectslist.projectnames(i).author()) {
					std::ifstream fin;
					std::string s1("./projects/"), s2("_"), s3("/project.bin"), s4;
					s4 = id + s2 + projectslist.projectnames(i).name();
					std::cout << (s1 + s4 + s3) << std::endl;
					//_chdir(&s4[0]);
					system("cd");
					fin.open(s1 + s4 + s3);
					if (!(this->project1.ParseFromIstream(&fin))) {
						std::cout << "Failed to parse project f. " << std::endl;
					}
					std::cout << this->project1.author() << this->project1.createddate();
					//_chdir("..");
					system("cd");
					fin.close();
					break;
				}
				else {
					std::cout << "Not authorized to access this project";
					break;
				}
			}
			if (i == this->projectslist.projectnames_size() - 1)
				std::cout << "Invalid Project Id";
		}
	}

	void writeProject() {
		std::ofstream fout;
		std::cout << "writing output";
		std::string s1("./projects/"), s2("_"), s3("/project.bin"), s4, s5, s6;
		s5 = project1.id();
		s6 = project1.name();
		s4 = s5 + s2 + s6;
		fout.open(&(s1 + s4 + s3)[0]);
		if (!this->project1.SerializePartialToOstream(&fout)) {
			std::cout << "Failed to write address book." << std::endl;
		}
		fout.close();
	}


	void createNewProject() {
		std::string name, id;
		project::ProjectHeader* newProject = this->projectslist.add_projectnames();

		newProject->set_author(this->username);

		std::cout << "Enter the project name: ";
		std::cin >> name;
		newProject->set_name(name);

		id = std::to_string(this->projectslist.projectnames_size());
		newProject->set_id(id);

		time_t my_time = time(NULL);
		printf("%s", ctime(&my_time));
		newProject->set_creationdate(ctime(&my_time));

		std::ofstream fout;
		fout.open("projects/projectheaders.bin", std::ios_base::binary);
		if (!this->projectslist.SerializeToOstream(&fout))
			std::cout << "Unable to write data" << std::endl;
		fout.close();


		project::Project p1;
		p1.set_id(id);
		p1.set_name(name);
		p1.set_author(this->username);
		p1.set_createddate(ctime(&my_time));

		std::string ud = "_";
		_chdir("projects");
		_mkdir(&(id + ud + name)[0]);
		fout.open(id + ud + name + "/" + "project.bin", std::ios::out);

		if (!p1.SerializeToOstream(&fout))
			std::cout << "Unable to write data";
		fout.close();
		_chdir("..");
	}

	void deleteProject(std::string id) {
		for (int i = 0; i < this->projectslist.projectnames_size(); i++) {
			if (id == projectslist.projectnames(i).id()) {// this->username == projectslist.projectnames(i).author()) {
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
		fout.open("projects/projectheaders.bin", std::ios_base::binary);
		if (!this->projectslist.SerializeToOstream(&fout))
			std::cout << "Unable to write data";
		fout.close();
	}

	void deleteAllProject() {
		int i = 0;
		while (i < this->projectslist.projectnames_size()) {
			std::cout << this->projectslist.projectnames(i).id() << std::endl;
			deleteProject(this->projectslist.projectnames(i).id());
		}
	}

	void printAllProjectsInfo() {

		for (int i = 0; i < this->projectslist.projectnames_size(); i++) {
			const project::ProjectHeader& projecti = this->projectslist.projectnames(i);
			//if (projecti.author() == this->username)
			std::cout << projecti.id() << "_" << projecti.name() << std::endl;
		}
	}

	void printProjectInfo(std::string id) {
		for (int i = 0; i < this->projectslist.projectnames_size(); i++) {
			const project::ProjectHeader& projecti = this->projectslist.projectnames(i);
			if (projecti.author() == this->username && projecti.id() == id) {
				std::cout << "ID: " << projecti.id() << std::endl;
				std::cout << "Name :" << projecti.name() << std::endl;
				std::cout << "Creation Date :" << projecti.creationdate() << std::endl;
				break;

			}
			else {
				std::cout << "User not authorized to access this project";
			}
		}

	}

	void addLine() {
		std::string line;
		std::cout << "enter the line to be added at last: ";
		std::cin.ignore();
		std::getline(std::cin, line);
		//line = "hello world";
		std::string* a = this->project1.add_text();
		*a = line;
		auto* change = this->project1.add_changes();
		change->set_opearationtype(project::ADD);
		change->set_linenum(this->project1.text_size());
		change->set_line0(this->project1.text(this->project1.text_size() - 1));

		updateLastModified();
		std::cout << "mark";
	}

	void printText() {
		for (int i = 0; i < project1.text_size(); i++) {
			std::cout << i + 1 << "  " << project1.text(i) << std::endl;
		}
	}

	void updateLine() {
		int ln;
		std::string updatedLine;
		std::cout << "Enter the line number to be updated: ";
		std::cin >> ln;
		std::cout << " Enter the text: ";
		std::cin.ignore();
		std::getline(std::cin, updatedLine);
		std::string prev = this->project1.text(ln - 1);
		project1.set_text(ln - 1, updatedLine);

		auto* change = this->project1.add_changes();

		change->set_opearationtype(project::UPDATE);
		change->set_linenum(ln);
		change->set_line0(prev);
		change->set_line1(project1.text(ln - 1));

		updateLastModified();

	}

	void removeLine() {
		int ln;
		std::cout << "Enter the line number to be removed: ";
		std::cin.ignore();
		std::cin >> ln;
		auto* change = this->project1.add_changes();

		change->set_opearationtype(project::DELETE);
		change->set_linenum(ln);
		change->set_line0(this->project1.text(ln - 1));

		auto* a = this->project1.mutable_text();
		while (ln < this->project1.text_size()) {
			std::cout << project1.text_size() << "dfadff";
			std::cout << ln << std::endl;
			a->SwapElements(ln - 1, ln);
			ln++;
		}
		
		a->RemoveLast();

		updateLastModified();
	}

	void updateLastModified() {
		time_t my_time = time(NULL);
		this->project1.set_lastmodified(ctime(&my_time));
	}

	void revertAddLine() {
		auto change = this->project1.changes(this->project1.changes_size() - 1);
		auto text = project1.mutable_text();
		text->RemoveLast();

		auto changes = project1.mutable_changes();
		changes->RemoveLast();

	}

	void revertUpdateLine() {
		auto change = this->project1.changes(this->project1.changes_size() - 1);
		std::string prevLine = change.line0();
		this->project1.set_text(change.linenum() - 1, prevLine);

		auto changes = this->project1.mutable_changes();
		changes->RemoveLast();
	}

	void revertRemoveLine() {
		auto change = this->project1.changes(this->project1.changes_size() - 1);
		this->project1.add_text();
		auto a = project1.mutable_text();
		int i = project1.text_size()-1;
		while (i >= change.linenum()) {
			a->SwapElements(i - 1, i);
			i--;
		}
		project1.set_text(change.linenum() - 1, change.line0());

		auto changes = project1.mutable_changes();
		changes->RemoveLast();

	}

	void revertLastChange() {
		auto change = this->project1.changes(this->project1.changes_size() - 1);
		switch (change.opearationtype())
		{
		case project::ADD:
			this->revertAddLine();
			break;
		case project::DELETE:
			this->revertRemoveLine();
			break;
		case project::UPDATE:
			this->revertUpdateLine();
			break;
		default:
			std::cout << "Error occured in decoding operation type" << std::endl;
		}
	}

	void printChanges() {
		for (int i = 0; i < project1.changes_size(); i++) {
			std::cout << project1.changes(i).opearationtype() << std::endl;
			std::cout << project1.changes(i).linenum() << std::endl;
			std::cout << project1.changes(i).line0() << std::endl;
			std::cout << project1.changes(i).line1() << std::endl;
			std::cout << std::endl;
		}
	}
};



