#include<queue>
#include<stack>
#include<set>
#include<map>
#include<limits>
#include<vector>
#include"unidirected_edge.hpp"

template<typename T>
class fifo{
private:
	std::queue<T> coda;
public:
	fifo() {}
	void put(const T& elemento){
		coda.push(elemento);}
	T get(){
		T elem=coda.front();
		coda.pop();
		return elem;}
	bool empty()const{
		return coda.empty();}	
};


template<typename T>
class lifo{
private:
	std::stack<T> stack;
public:
	lifo() {}
	void put(const T& elemento){
		stack.push(elemento);}
	T get(){
		T val=stack.top();
		stack.pop();
		return val;}
	bool empty()const{
		return stack.empty();}	
};

template<typename Contenitore,typename T>
unidirected_graph<T> graph_visit(const unidirected_graph<T>& G, const T& v,Contenitore& cont){
	
	unidirected_graph<T> albero_risultante;
	std::map<T,bool> reached;
	cont.put(v);
	reached[v]=true;
	while(!cont.empty()){
		T u=cont.get();
		for(const T& w: G.neighbours(u)){
			if(reached[w]==false){
				reached[w]=true;
				albero_risultante.add_edge(u,w);
				cont.put(w);
			}
		}
	}
	return albero_risultante;
}

	

template<typename T>
void recursive_dfs_help(const unidirected_graph<T>& G,const T& u, std::map<T,bool>& reached, unidirected_graph<T>& albero){
	reached[u]=true;
	for(const T& w: G.neighbours(u)){
		if(reached[w]==false){
			albero.add_edge(u,w);
			recursive_dfs_help(G,w,reached,albero);
		}
	}
}

template<typename T>
unidirected_graph<T> recursive_dfs(const unidirected_graph<T>& G, const T& v){
	unidirected_graph<T> albero_risultante;
	std::map<T,bool> reached;
	recursive_dfs_help(G,v,reached, albero_risultante);
	return albero_risultante;
}


template<typename T>
unidirected_graph<T> dijkstra(const unidirected_graph<T>& G, const T& sorgente){
	unidirected_graph<T> albero_cammini;
	std::map<T, double> distanze;
	std::map<T,T> predecessori;
	for (const T& w : G.all_nodes()){
		distanze[w]=std::numeric_limits<double>::infinity();
	}
	distanze[sorgente]=0.0;
	using ElemCoda=std::pair<double, T>;
	std::priority_queue<ElemCoda> p;
	p.push({0.0,sorgente});
	while(!p.empty()){
		auto primo_elem=p.top();
		p.pop();
		double dist_u=-primo_elem.first; //uso il meno per "invertire" la priorità della coda
		T u=primo_elem.second;
		if(dist_u<=distanze[u]){
			if (predecessori.find(u)!= predecessori.end()){
			albero_cammini.add_edge(predecessori[u],u);}
			
			for(const T& w: G.neighbours(u)){
				double peso_arco=1.0;
				
				if (distanze[u]+peso_arco< distanze[w]){
					distanze[w]=distanze[u]+peso_arco;
					predecessori[w]=u;
					
					p.push({-distanze[w],w});
				}
			}
		}
	}
	return albero_cammini;
}
		
	






	
		
		
	