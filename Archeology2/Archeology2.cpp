#include "Artefact.h"
#include "PotteryItem.h"
#include <string>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<PotteryItem> input_data();
void display_items(vector<PotteryItem> items);
void search_by_culture(vector<PotteryItem> items);
void display_same_region(vector<PotteryItem> items);
bool is_numeric(const string& str);
int get_item_count();
int get_current_year();
int get_year(int i);

int main()
{
    vector<PotteryItem> items = input_data();
    display_items(items);
    search_by_culture(items);
    display_same_region(items);
    return 0;
}

vector<PotteryItem> input_data() {
    int item_count = get_item_count();
    vector<PotteryItem> items;

    for (int i = 0; i < item_count; i++) {
        int year;
        string region, type, culture, material;

        year = get_year(i);
        printf("Enter region of excavation of pottery item number %d: ", i + 1);
        getline(cin, region);
        printf("Enter type of pottery item number %d: ", i + 1);
        getline(cin, type);
        printf("Enter culture of pottery item number %d: ", i + 1);
        getline(cin, culture);
        printf("Enter material of pottery item number %d: ", i + 1);
        getline(cin, material);
        items.emplace_back(PotteryItem(i + 1, region, year, type, culture, material));
    }
    return items;
}

void display_items(vector<PotteryItem> items) {
    cout << "\nInfo about pottery items:\n";

    for (int i = 0; i < items.size(); i++) {
        items[i].display_data();
    }
}

void search_by_culture(vector<PotteryItem> items) {
    int count = 0;
    string culture;
    cout << "\nPottery items from culture: ";
    getline(cin, culture);

    for (int i = 0; i < items.size(); i++) {
        if (items[i].get_culture() == culture) {
            items[i].display_data();
            count++;
        }
    }

    if (count == 0) {
        cout << "No items from " << culture << " culture." << endl;
    }
}

void display_same_region(vector<PotteryItem> items) {
    cout << "\nPottery items with same region of excavation: " << endl;

    int count = 0;
    vector<PotteryItem> checked;

    for (int i = 0; i < items.size(); i++) {
        vector<PotteryItem> same_region;
        same_region.emplace_back(items[i]);
        bool should_break = false;

        //checks if the current region has already been iterated through
        for (int j = 0; j < checked.size(); j++) {
            if (items[i].is_equal_to(checked[j])) {
                should_break = true;
                break;
            }
        }

        if (should_break == true) {
            break;
        }

        checked.emplace_back(items[i]);

        //checks for region matches and collects them + marks them as checked
        for (int j = i + 1; j < items.size(); j++) {
            if (items[i].get_region() == items[j].get_region()) {
                same_region.emplace_back(items[j]);
                checked.emplace_back(items[j]);
                count++;
            }
        }

        //if there are more than 1 items with the same region, it displays their data
        if (same_region.size() > 1) {
            for (int j = 0; j < same_region.size(); j++) {
                same_region[j].display_data();
            }
        }

        if (count != 0) {
            cout << "\n";
        }
    }

    if (count == 0) {
        cout << "None." << endl;
    }
}

bool is_numeric(const string& input) {
    if (input.empty()) return false;

    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int get_item_count() {
    cout << "Enter count of pottery items (<= 100): ";
    int item_count;
    string count_input;
    getline(cin, count_input);

    while (!is_numeric(count_input) || stoi(count_input) < 0 || stoi(count_input) > 100) {
        cout << "Invalid count. Please try again: ";
        getline(cin, count_input);
    }

    item_count = stoi(count_input);
    return item_count;
}

int get_current_year() {
    std::time_t t = std::time(nullptr); // Get current time
    std::tm timeInfo;                   // Create a local time structure
    if (localtime_s(&timeInfo, &t) != 0) {
        return -1;                      // Handle error if `localtime_s` fails
    }
    return 1900 + timeInfo.tm_year;     // Return the current year
}

int get_year(int i) {
    printf("Enter year of excavation of pottery item number %d: ", i + 1);
    int year;
    string year_input;
    getline(cin, year_input);

    while (!is_numeric(year_input) || stoi(year_input) < 0 || stoi(year_input) > get_current_year()) {
        cout << "Wrong year. Please try again: ";
        getline(cin, year_input);
    }

    year = stoi(year_input);
    return year;
}
