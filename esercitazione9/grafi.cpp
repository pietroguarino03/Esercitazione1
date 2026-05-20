#include <iostream>
#include <fstream>
#include "visita_grafi.hpp"
template<typename T>
void file_graphviz(const unidirected_graph<T>& G, const std::string& nome_file){
	std::ofstream file(nome_file);
	if(file.is_open()){
		file<< "graph G {\n";
		for(const auto& arco:G.all_edges()){
			file<<"  \""<<arco.from()<<"\" -- \""<<arco.to()<<"\";\n";
		}
		file<<"}\n";
		file.close();
		std::cout<< "File salvato: "<<nome_file<<"\n";
	}
	else{
		std::cerr<<"Errore creazione file: "<<nome_file<<"\n";
	}
}
int main(){
	unidirected_graph<int> G;
	G.add_edge(1,2);
	G.add_edge(1,3);
	G.add_edge(2,4);
	G.add_edge(3,5);
	G.add_edge(4,5);
	file_graphviz(G, "grafo_originale.dot");
	
	//BFS
	fifo<int> cont_fifo;
	unidirected_graph<int> albero_bfs=graph_visit(G,1,cont_fifo);
	file_graphviz(albero_bfs, "albero_bfs.dot");
	
	
	//DFS ITERATIVA
	lifo<int> cont_lifo;
	unidirected_graph<int> albero_dfs=graph_visit(G,1,cont_lifo);
	file_graphviz(albero_dfs, "albero_dfs.dot");
	
	//DFS RICORSIVA
	unidirected_graph<int> albero_dfs_ricorsivo=recursive_dfs(G,1);
	file_graphviz(albero_dfs_ricorsivo, "albero_dfs_ricorsivo.dot");
	
	//DIJKSTRA
	unidirected_graph<int> albero_cammini_minimi=dijkstra(G,1);
	file_graphviz(albero_cammini_minimi, "albero_cammini_minimi.dot");
	
	return 0;
}