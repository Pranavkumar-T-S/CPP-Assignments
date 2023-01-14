#include <fstream>
#include <iostream>
#include "imgmask.pb.h"
#include "protobuf_handler.hpp"

std::string x_param[2] = {"Blue", "Hue"}, y_param[2] = {"Green", "Saturation"}, z_param[2] = {"Red", "Value"};

ProtobufHandler::ProtobufHandler(std::string filename)
{
	this->filename = filename;

	if (!this->load())
	{
		std::cout << "Failed to parse protobuf setting default values." << std::endl;
		this->set_default_values();
		this->dump();
	}
}

void ProtobufHandler::set_default_values()
{
	this->mask1.set_xmin(0);
	this->mask1.set_xmax(255);
	this->mask1.set_ymin(0);
	this->mask1.set_ymax(255);
	this->mask1.set_zmin(0);
	this->mask1.set_zmax(255);
}

bool ProtobufHandler::load()
{
	std::ifstream fin;
	fin.open(this->filename);
	std::string temp;
	std::getline(fin, temp);
	std::cout << this->filename << std::endl;
	std::cout << temp << std::endl;
	bool status = this->mask1.ParseFromString(temp);
	fin.close();
	std::cout << this->mask1.xmin() << ' ' << this->mask1.xmax() << std::endl;
	return status;
}

bool ProtobufHandler::dump()
{
	std::ofstream fout;
	std::string temp;
	bool status;
	std::cout << this->filename;
	fout.open(this->filename);
	std::cout << "fd" << this->mask1.xmax() << this->mask1.xmin() << std::endl;
	this->mask1.SerializeToString(&temp);
	std::cout << "re" << temp << "ew" << std::endl;
	fout.write(temp.c_str(), temp.size());
	fout.close();
	return true;
}

void ProtobufHandler::user_prompt_values()
{
	int tempcs, tempvalue;
	std::cout << "Enter the colorspace and values to filterout " << std::endl;
	std::cout << "Enter the filter's colorspace: (0 - BGR, 1 - HSV): ";
	std::cin >> tempcs;
	std::cout << std::endl;
	mask1.set_cstype(tempcs == 0 ? imgmask::BGR : imgmask::HSV);
	std::cout << "Enter the Minimum " << x_param[tempcs] << ": ";
	std::cin >> tempvalue;
	std::cout << std::endl;
	mask1.set_xmin(tempvalue);
	// std::cout << mask1.xmin();
	std::cout << "Enter the Maximum " << x_param[tempcs] << ": ";
	std::cin >> tempvalue;
	std::cout << std::endl;
	mask1.set_xmax(tempvalue);
	// std::cout << mask1.xmax();

	std::cout << "Enter the Minimum " << y_param[tempcs] << ": ";
	std::cin >> tempvalue;
	std::cout << std::endl;
	mask1.set_ymin(tempvalue);
	// std::cout << mask1.ymin();
	std::cout << "Enter the Maximum " << y_param[tempcs] << ": ";
	std::cin >> tempvalue;
	std::cout << std::endl;
	mask1.set_ymax(tempvalue);
	// std::cout << mask1.ymax();

	std::cout << "Enter the Minimum " << z_param[tempcs] << ": ";
	std::cin >> tempvalue;
	std::cout << std::endl;
	mask1.set_zmin(tempvalue);
	// std::cout << mask1.zmin();
	std::cout << "Enter the Maximum " << z_param[tempcs] << ": ";
	std::cin >> tempvalue;
	std::cout << std::endl;
	mask1.set_zmax(tempvalue);
	// std::cout << mask1.zmax();
}

ProtobufHandler::~ProtobufHandler()
{
	if (this->dump())
	{
		std::cout << "mask configuration stored" << std::endl;
	}
	else
	{
		std::cout << "unable to store mask configuration" << std::endl;
	}
}

struct maskdata ProtobufHandler::get_mask_data()
{
	struct maskdata temp
	{
		mask1.cstype(), mask1.xmin(), mask1.xmax(), mask1.ymin(), mask1.ymax(), mask1.zmin(), mask1.zmax()
	};
	return temp;
}
