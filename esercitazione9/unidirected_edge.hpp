#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>

template<typename T>
class unidirected_edge{
private:
	T nodo_from;
	T nodo_to;
public:
	unidirected_edge(T a, T b){
		nodo_from=std::min(a,b);
		nodo_to=std::max(a,b);
	}

	T from() const{
		return nodo_from;
		}	
	T to() const{
		return nodo_to;
	}

	bool operator<(const unidirected_edge& other)const{
		if (nodo_from != other.from()){
			return nodo_from<other.from();
		}
		else	
			return nodo_to<other.to();
	}

	bool operator==(const unidirected_edge& other)const{
		return nodo_from==other.from() && nodo_to==other.to();
	}
};
template<typename T>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<T>& e) {
    os << "(" << e.from() << ", " << e.to() << ")";
    return os;
}

template<typename T>
class unidirected_graph{
private:
	std::map<T, std::set<T>> adjacency_list;
	std::vector<unidirected_edge<T>> edges;
public:
	unidirected_graph(){
	}
	unidirected_graph(const unidirected_graph& other){
		this->adjacency_list=other.adjacency_list;
		this->edges=other.edges;
	}
	
	//NEIGHBOURS
	std::set<T> neighbours(const T& nodo) const{
		auto it=adjacency_list.find(nodo);
		if (it!=adjacency_list.end()){
			return it-> second;
		}
		return {};
	}
			
	
	//ADD EDGE
	void add_edge(const T& a,const T& b){
		unidirected_edge<T> new_edge(a, b);
		if(std::find(edges.begin(),edges.end(),new_edge)==edges.end()){
			edges.push_back(new_edge);
			adjacency_list[new_edge.from()].insert(new_edge.to());
            adjacency_list[new_edge.to()].insert(new_edge.from());
		}
	}
	
	

	//ALL NODES
	std::set<T> all_nodes() const {
		std::set<T> nodi;
		for (const auto& pair:adjacency_list){
			nodi.insert(pair.first);
		}
		return nodi;
	}
	
	//ALL EDGES
	std::vector<unidirected_edge<T>> all_edges() const {
		return edges;
	}
	
	//EDGE NUMBER
	int edge_number(const unidirected_edge<T>& arco) const {
		for (size_t i=0; i<edges.size(); i++){
			if (arco==edges[i]){
				return i;
			}
		}
		return -1;
	}
	
	//EDGE AT
	unidirected_edge<T> edge_at( const int& i) const {
		return edges.at(i);
	}
	
	
	//DIFFERENZA
	unidirected_graph operator-(const unidirected_graph& other)const {
		unidirected_graph differenza;
		auto other_edges=other.all_edges();
		for (const auto& e : this->edges) {
            if (std::find(other_edges.begin(), other_edges.end(), e) == other_edges.end()) {
                differenza.add_edge(e.from(), e.to());
            }
        }
        return differenza;
    }
};
		
		

		
		
	