#include "mydatastore.h"
MyDataStore::MyDataStore(){

}
void MyDataStore::addProduct(Product* p){
  products.push_back(p);
	//get keywords for product 
	std::set<std::string> keywords = p->keywords();
	std::set<std::string>::iterator i;
	//loop through each keyword
	for(i=keywords.begin(); i!=keywords.end(); i++){
	//if keyword is not in map insert new key value pair
		if(searchMap.find(*i)==searchMap.end()){
			std::set<Product*> prods;
			prods.insert(p);
			searchMap.insert({*i, prods});
		}
		else{
			//otherwise, add product to set with the existing keyword
			searchMap[*i].insert(p);
		}
	}
}
/**
* Adds a user to the data store
*/
void MyDataStore::addUser(User* u){
	users.push_back(u);
	userMap.insert({u->getName(), u});
}

/**
* Performs a search of products whose keywords match the given "terms"
*  type 0 = AND search (intersection of results for each term) while
*  type 1 = OR search (union of results for each term)
*/
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	//define vector of sets to be populated in the search map
	std::vector<std::set<Product*>> prodSetList;
	for(unsigned int i=0; i<terms.size(); i++){
		//check if term is in searchMap 
		if(searchMap.find(terms.at(i))!=searchMap.end()){
			std::set<Product*> prodSet = searchMap[terms.at(i)];
			//add set to vector 
			prodSetList.push_back(prodSet);
		}
	}
	std::set<Product*> matches;
		for(unsigned int i=0; i<prodSetList.size(); i++){
			//if its the first set add it to matches
			if(i==0){
				matches = prodSetList.at(i);
			}
			else{
				//0 means intersection
				if(type==0){
					matches = setIntersection(matches,prodSetList.at(i));
				}
				else{
					matches = setUnion(matches, prodSetList.at(i));
				}
			}
		}
		std::vector<Product*> result;
		//copy set to vector to return proper type
		result.assign(matches.begin(), matches.end());
		return result;
}

/**
* Reproduce the database file from the current Products and User values
*/
void MyDataStore::dump(std::ostream& ofile){
	ofile<<"<products>\n";
	for(unsigned int i=0; i<products.size(); i++){
		products.at(i)->dump(ofile);
	}
	ofile<<"</products>\n";
	
	ofile<<"<users>\n";
	for(unsigned int i=0; i<users.size(); i++){
		users.at(i)->dump(ofile);
	}
	ofile<<"</users>\n";
}
std::map<std::string, User*> MyDataStore::getUserMap(){
 return userMap;
}

