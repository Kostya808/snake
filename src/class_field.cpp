#include <class_field.h>
#include <class_fruit.h>
#include <class_head.h>

void Fields::initial_snake_making(Head *h){
	snake_matrix[h->Get_X()][h->Get_Y()] = h->Get_Type_head();
	h->next = create_body(h);
	create(h->next, h);
	create(h->next, h);
}

int Fields::field_update(Fruit *f1, Fruit *f2, Head *h) {
	int buf_x, buf_y, buf2_x, buf2_y, flag = 0;
	Body* bypass = h->next;
	buf_x = h->Get_X();
	buf_y = h->Get_Y();
	if(h->Get_X() != h->Get_new_x() || h->Get_Y() != h->Get_new_y()) {
		snake_matrix[h->Get_new_x()][h->Get_new_y()] = h->Get_Type_head();
		while(bypass != NULL) {
			buf2_x = bypass->Get_X();
			buf2_y = bypass->Get_Y();
			snake_matrix[buf2_x][buf2_y] = 0;
			snake_matrix[buf_x][buf_y] = h->Get_Type_body();
			bypass->Set(buf_x, buf_y);
			bypass = bypass->next;
			buf_x = buf2_x;
			buf_y = buf2_y;
		}
		h->tail->Set(buf2_x, buf2_y);
		buf2_x = 0;
		buf2_x = 0;
		if (f1->Get_X() == h->Get_new_x() && f1->Get_Y() == h->Get_new_y()) {
			eating_fruit(f1, h);
			flag = 1;
		}
		if (f2->Get_X() == h->Get_new_x() && f2->Get_Y() == h->Get_new_y()) {
			eating_fruit(f2, h);
			flag = 1;
		}
		h->Set(h->Get_new_x(), h->Get_new_y());
	}
	if (flag == 1)
		return 1;
	return 0;
}

void Fields::eating_fruit(Fruit *f, Head *h) {
	h->Set_score(h->Get_score() + f->Get_score());
	if (f->Get_growth() == 1) {
		create(h->next, h);
	}
	else if (f->Get_growth() == 2) {
		create(h->next, h);
		create(h->next, h);
	}
	f->Set_life(0);
	f->Set(size, size);
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
	if (h->tail->Get_X() < size -1) {
		if (snake_matrix[h->tail->Get_X() + 1][h->tail->Get_Y()] == 0 && flag == 0) {
			x = h->tail->Get_X() + 1;
			y = h->tail->Get_Y();
			flag = 1;
		}
	}
		if (snake_matrix[h->tail->Get_X() - 1][h->tail->Get_Y()] == 0 && flag == 0) {
		x = h->tail->Get_X() - 1;
		y = h->tail->Get_Y();
		flag = 1;
	}
	if (h->tail->Get_Y() < size - 1) {
		if (snake_matrix[h->tail->Get_X()][h->tail->Get_Y() + 1] == 0 && flag == 0) {
			x = h->tail->Get_X();
			y = h->tail->Get_Y() + 1;
			flag = 1;
		}
	}
		if (snake_matrix[h->tail->Get_X()][h->tail->Get_Y() - 1] == 0 && flag == 0) {
		x = h->tail->Get_X();
		y = h->tail->Get_Y() - 1;
		flag = 1;
	}
	if(flag == 1) {
		Body* body = new Body(x, y);
		h->tail->Set(x, y);
		return body;
	}
	return NULL;
}