// Kruskal’s Algorithm is a Greedy Algorithm used 
// to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph.

/*
MST ek aisa tree hota hai jo:
->Saare vertices ko connect karta hai (koi disconnected part nahi hota)
->Cycle nahi banata
->Total edge weight sabse kam hota hai
*/
/*
Algorithm ke Steps

1. Saare edges ko sort karo — unke weight ke increasing order me.
2. Chhote se bada edge ek ek karke uthao.
3. Har edge add karne se pehle check karo ki cycle ban rahi hai ya nahi
  ->Agar cycle nahi banti, to edge include karo.
  ->Agar cycle banti hai, to skip karo.
4. Jab tak tumhare paas (V - 1) edges na ho jaye, ye process repeat karo.
*/