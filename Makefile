lazysnapping: maxflow-v3.01/graph.cpp maxflow-v3.01/maxflow.cpp saliency.cpp fresaliency.cpp fresalgc.cpp
	g++ `pkg-config opencv --libs --cflags opencv` maxflow-v3.01/graph.cpp maxflow-v3.01/maxflow.cpp fresaliency.cpp fresalgc.cpp saliency.cpp -o saliency
