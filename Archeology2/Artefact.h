#include <string>
#include <iostream>

using namespace std;

#pragma once
class Artefact
{
private:
	int id, year_of_excavation;
	string region_of_excavation;

public:
	Artefact() {}

	Artefact(int id, string region, int year) {
		this->id = id;
		region_of_excavation = region;
		year_of_excavation = year;
	}

	~Artefact() {}

	int get_id() {
		return id;
	}

	void set_id(int id) {
		this->id = id;
	}

	string get_region() {
		return region_of_excavation;
	}

	void set_region(string region) {
		this->region_of_excavation = region;
	}

	int get_year() {
		return year_of_excavation;
	}

	void set_year(int year) {
		year_of_excavation = year;
	}

	virtual void display_data() {
		printf("Artefact number %d: excavated at %d in %s\n",
			id, year_of_excavation, region_of_excavation.c_str());
	}
};