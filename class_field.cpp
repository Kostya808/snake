#include "class_field.h"
#include "class_fruit.h"
#include "class_head.h"

void Fields::initial_snake_making(Head *h){
	snake_matrix[h->x][h->y] = h->type_head;
	h->next = create_body(h);
	create(h->next, h);
	create(h->next, h);
}

int Fields::field_update(Fruit *f1, Fruit *f2, Head *h) {
	int buf_x, buf_y, buf2_x, buf2_y, flag = 0;
	Body* bypass = h->next;
	buf_x = h->x;
	buf_y = h->y;
	if(h->x != h->new_x || h->y != h->new_y) {
		snake_matrix[h->new_x][h->new_y] = h->type_head;
		while(bypass != NULL) {
			buf2_x = bypass->x;
			buf2_y = bypass->y;
			snake_matrix[buf2_x][buf2_y] = 0;
			snake_matrix[buf_x][buf_y] = h->type_body;
			bypass->x = buf_x;
			bypass->y = buf_y;
			bypass = bypass->next;
			buf_x = buf2_x;
			buf_y = buf2_y;
		}
		h->tail->x = buf2_x;
		h->tail->y = buf2_y;
		buf2_x = 0;
		buf2_x = 0;
		if (f1->x == h->new_x && f1->y == h->new_y) {
			eating_fruit(f1, h);
			flag = 1;
		}
		if (f2->x == h->new_x && f2->y == h->new_y) {
			eating_fruit(f2, h);
			flag = 1;
		}
		h->x = h->new_x; 
		h->y = h->new_y;
	}
	if (flag == 1)
		return 1;
	return 0;
}

void Fields::eating_fruit(Fruit *f, Head *h) {
	h->score += f->score;
	if (f->growth == 1) {
		create(h->next, h);
	}
	else if (f->growth == 2) {
		create(h->next, h);
		create(h->next, h);
	}
	f->life = 0;
	f->x = size;
	f->y = size;
}

void Fields::create(Body *&node, Head *h) {
	if(node == NULL) {
		node = create_body(h);
	}
	else {
		create(node->next, h);
	}
}

Body* Fields::create_body(Head *h) {
	int x, y, flag = 0;
	if (h->tail->x < size -1) {
		if (snake_matrix[h->tail->x + 1][h->tail->y] == 0 && flag == 0) {
			x = h->tail->x + 1;
			y = h->tail->y;
			flag = 1;
		}
	}
		if (snake_matrix[h->tail->x - 1][h->tail->y] == 0 && flag == 0) {
		x = h->tail->x - 1;
		y = h->tail->y;
		flag = 1;
	}
	if (h->tail->y < size - 1) {
		if (snake_matrix[h->tail->x][h->tail->y + 1] == 0 && flag == 0) {
			x = h->tail->x;
			y = h->tail->y + 1;
			flag = 1;
		}
	}
		if (snake_matrix[h->tail->x][h->tail->y - 1] == 0 && flag == 0) {
		x = h->tail->x;
		y = h->tail->y - 1;
		flag = 1;
	}
	if(flag == 1) {
		Body* body = new Body(x, y);
		h->tail->x = x;
		h->tail->y = y;
		return body;
	}
	return NULL;
}