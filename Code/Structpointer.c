struct example{
    int a;
    int b;
}e;
// Pointer to a struct
struct example *p1 = &e;
// Pointer to an element of a struct
int *p2 = &e.a;

// Access a member of a struct
ea = (*p1).a;
ea = p1->a;