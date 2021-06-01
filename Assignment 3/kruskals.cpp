void Kruskals() {
        // write your code here
        DisjointSet ds;
        for(int i = 0; i < N_VERTICES; i++)
        {
                ds.make_set(i);
        }

        Edge e[10000];
        int a = create_edge_list(e);

        sort_edge_list(e, a);

        for(int i=0; i<N_VERTICES; i++)
        {
                for(int j=0; j < N_VERTICES; j++)
                {
                        if(mat[i][j] != 0) {
                                int u=i;
                                int v=j;
                                if(ds.find_set(u) != ds.find_set(v)) {
                                        std::cout << u << " " << v << '\n';
                                        ds.union_set(ds.find_set(u), ds.find_set(v));
                                }

                        }
                }
        }
}

};

int main()
{

        Graph G;
        G.init_graph();
        // G.add_edge(0, 1, 4);
        // G.add_edge(1, 2, 9);
        // G.add_edge(1, 4, 2);
        // G.add_edge(3, 4, 15);
        // G.add_edge(4, 5, 8);
        // G.add_edge(5, 6, 3);
        // G.add_edge(5, 7, 10);
        // G.add_edge(6, 7, 14);
        // G.add_edge(1, 7, 5);
        // G.add_edge(0, 7, 6);

        G.add_edge(0, 1, 2);
        G.add_edge(1, 2, 19);
        G.add_edge(2, 3, 9);
        G.add_edge(3, 4, 1);
        G.add_edge(4, 5, 13);
        G.add_edge(5, 6, 21);
        G.add_edge(0, 5, 14);
        G.add_edge(0, 6, 8);
        G.add_edge(1, 5, 25);
        G.add_edge(2, 5, 13);
        G.add_edge(2, 4, 5);

        G.Kruskals();

        return 0;
}
