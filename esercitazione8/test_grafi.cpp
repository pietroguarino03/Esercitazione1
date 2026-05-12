#include<iostream>
#include"unidirected_edge.hpp"


int main() {
    unidirected_graph<int> g1;
    g1.add_edge(1, 2);
    g1.add_edge(2, 3);
    g1.add_edge(1, 3);
	g1.add_edge(1, 2);

    unidirected_graph<int> g2;
    g2.add_edge(1, 2);
	
	//Test duplicati
	std::cout<<"-----TEST DUPLICATI-----"<<"\n";
	if (g1.all_edges().size()==3){
		std::cout<<"Il grafo g1 ha "<<g1.all_edges().size()<<" archi,non ha archi duplicati, test superato."<<"\n";
		std::cout<<" "<<"\n";
	}
	else
		return -1;
	
	//Test vicini
	std::cout<<"-----TEST VICINI-----"<<"\n";
	auto vicini_nodo_1=g1.neighbours(1);
	if(vicini_nodo_1.count(2) && vicini_nodo_1.count(3)){
		std::cout<<"I vicini del nodo 1 sono i nodi 2 e 3, test superato."<<"\n";
		std::cout<<" "<<"\n";
	}
	else
		return -1;
	
	//Test all nodes
	std::cout<<"-----TEST ALL NODES-----"<<"\n";
	auto nodi_totali=g1.all_nodes();
	if(nodi_totali.size()==3){
		std::cout<<"I nodi presenti sono: ";
		for(const auto& nodo:nodi_totali){
			std::cout<<nodo<<",";
		}
		std::cout<<" test superato."<<"\n";
		std::cout<<" "<<"\n";
	}
	else
		return -1;
	
	
	//Test edge number, edge at
	std::cout<<"-----TEST EDGE NUMBER, EDGE AT-----"<<"\n";
	unidirected_edge<int> arco_cercato(3,2);
	int indice=g1.edge_number(arco_cercato);
	if (indice!=-1){
		auto arco_recuperato=g1.edge_at(indice);
		if (arco_cercato==arco_recuperato){
			std::cout<<"Individuamento arco tramite indice ,("<<indice<<"), e viceversa riuscito."<<"\n";
			std::cout<<" "<<"\n";
		}
	}
	else 
		return -1;
	
	
	std::cout<<"-----TEST DIFFERENZA TRA GRAFI-----"<<"\n";
	unidirected_graph<int> diff = g1 - g2;

    std::cout << "Archi in g1 - g2:" << std::endl;
    for (const auto& e : diff.all_edges()) {
        std::cout << e << " "<<"\n";
    }

    return 0;
}