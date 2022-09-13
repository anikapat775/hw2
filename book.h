#include "product.h"
class Book: public Product{
	public: 
	Book(const std::string name, double price, int qty, const std::string isbn, const std::string author);
	std::set<std::string> keywords() const;
	std::string displayString() const;
	void dump(std::ostream& os);
	std::string getIsbn();
	std::string getAuthor();
	void setIsbn(std::string isbn);
	void setAuthor(std::string author);
	private:
	std::string isbn_;
	std::string author_;
};