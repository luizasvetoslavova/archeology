#include "Artefact.h"
#include <string>

#pragma once
class PotteryItem : public Artefact
{
private:
	string type, culture, material;

public:
	PotteryItem() {}

	PotteryItem(int id, string region, int year, string type, string culture, string material) {
		set_id(id);
		set_region(region);
		set_year(year);
		this->type = type;
		this->culture = culture;
		this->material = material;
	}

	~PotteryItem() {}

	string get_type() {
		return type;
	}

	string get_culture() {
		return culture;
	}

	string get_material() {
		return material;
	}

	void display_data() override {
		printf("Pottery item number %d: excavated at %d in %s, from %s type, %s culture and %s material\n",
			get_id(), get_year(), get_region().c_str(), type.c_str(), culture.c_str(), material.c_str());
	}

	bool is_equal_to(PotteryItem another) {
		return get_id() == another.get_id() && get_region() == another.get_region() && get_year() == another.get_year() &&
			type == another.get_type() && culture == another.get_culture() && material == another.get_material();
	}
};