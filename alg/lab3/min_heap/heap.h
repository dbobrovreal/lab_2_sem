#include <stdlib.h> 

struct heapnode {
	int key; /* Приоритет (ключ) */
	int value; /* Значение */
};

struct heap {
	int maxsize; /* Максимальный размер кучи */
	int nnodes; /* Число элементов */
	struct heapnode *nodes; /* Массив элементов. Для удобства реализации элементы нумеруются с 1 */
};

struct heap *heap_create(int maxsize);
void heap_free(struct heap *h);
void heap_swap(struct heapnode *a, struct heapnode *b);
struct heapnode *heap_min(struct heap *h);
int heap_insert(struct heap *h, int key, int value);
struct heapnode heap_extract_min(struct heap *h);
void heap_heapify(struct heap *h, int index);
int heap_decrease_key(struct heap *h, int index, int newkey);
