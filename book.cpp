	#include "book.h"
	Book::Book(const std::string name, double price, int qty, const std::string isbn, const std::string author)
	: Product("book", name, price, qty)
	{
		isbn_= isbn;
		author_=author;
	}
	std::set<std::string> Book::keywords() const{
		//book can be searched by author, isbn, and name
		std::set<std::string> keys = parseStringToWords(author_);
		keys.insert(isbn_);
		std::set<std::string> names = parseStringToWords(name_);
		keys.insert(names.begin(), names.end());
		return keys;
	}
	std::string Book::displayString() const{
		return name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + " left."; 
}
	void Book::dump(std::ostream& os) const {
		Product::dump(os);
		os << isbn_ << "\n" << author_ << "\n";
	}
	std::string Book::getIsbn(){
		return isbn_;
	}
	std::string Book::getAuthor(){
		return author_;
	}
	void Book::setIsbn(std::string isbn){
		isbn_=isbn;
	}
	void Book::setAuthor(std::string author){
		author_=author;
	}