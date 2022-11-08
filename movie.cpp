#include "movie.h"
	Movie::Movie(const std::string name, double price, int qty, const std::string genre, const std::string rating)
	: Product("movie", name, price, qty)
	{
		genre_= genre;
		rating_=rating;
	}
	std::set<std::string> Movie::keywords() const{
		//movie can be searched by genre or name
		std::set<std::string> keys = parseStringToWords(genre_);
		//keys.insert(genre_);
		std::set<std::string> names = parseStringToWords(name_);
		keys.insert(names.begin(), names.end());
		return keys;
	}
	std::string Movie::displayString() const{
		return  name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + std::to_string(price_) + "\n" + std::to_string(qty_) + " left."; 
}
	void Movie::dump(std::ostream& os) const{
		Product::dump(os);
		os << genre_ << "\n" << rating_ << "\n"; 
	}
	std::string Movie::getGenre(){
		return genre_;
	}
	std::string Movie::getRating(){
		return rating_;
	}
	void Movie::setGenre(std::string genre){
		genre_=genre;
	}
	void Movie::setRating(std::string rating){
		rating_=rating;
	}