Project documentation file: https://docs.google.com/document/d/1lNrPGvhLDzKDvSMkmcgDotu6GDV-wOiQjIwxlCilU7Y/edit?usp=sharing


**Assignment**

- Design and implement an application that serves as a system for storing and processing information about archeological artefacts.
- Define a class Artefact with private fields for: ID number, region of excavation, year of excavation. 
- Add suitable constructors, destructor, access methods, and a method for printing information.
- Define a class PotteryItem as a subclass of the Artefact class with private fields for: type, culture, material.
- Add suitable constructors, a destructor, access methods. 
- Override the method that prints the complete information about a PotteryItem.
- Define main() function that processes the information about artefacts. 
- Enter data for P pottery items (P <= 100) from the keyboard and add them into an array. 
- Print information about all pottery items. 
- Print the information about the pottery items from a specific culture. The culture is entered from the keyboard. 
- Print the information about the pottery items with the same region of excavation.

**How the program works** (input/output)

- The program works by firstly asking the user about the count of the pottery items that would be added to the database. That number decides how many items, and accordingly how many times the console is going to ask the user about years, regions, types, cultures and materials of excavation. When the user enters a count number, that’s going to be the id of the last item; the first one would be 1, the second - 2, and so on.
- After the user inputs the data, the validation methods check if it’s right. For example, you can’t write a year of excavation that’s in the future or write a word instead of a number. 
- When all the data from the keyboard is in the right format, the program displays formatted information about all pottery items that have been entered. That’s a confirmation that the input part is successfully done and the information is added and stored to the data structure.
- Then, the console interface asks the user to enter a culture to search by. If such a culture exists in the database, the program displays formatted information about all the pottery items that come from that culture. If there are no matches, the program displays ‘No items from x culture’.
- In the end, without any need of external input, the console shows a list of all items with the same region of excavation. If there is more than one region that has been shared, the program displays both (or all) the pottery items with regions that appear more than once in the database. If there are no matches, the console prints ‘None’.
