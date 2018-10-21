#include "class_field.h"
#include "class_fruit.h"
#include <stdio.h>

void Fields::field_update(Fruit *f) {
	int buf_x, buf_y, buf2_x, buf2_y;
	Body* bypass = head1.next;
	buf_x = head1.x;
	buf_y = head1.y;
	if(head1.x != head1.new_x || head1.y != head1.new_y) {
		while(bypass != NULL) {
			buf2_x = bypass->x;
			buf2_y = bypass->y;
			snake_matrix[buf2_x][buf2_y].type = 0;
			snake_matrix[buf_x][buf_y].type = 2;
			bypass->x = buf_x;
			bypass->y = buf_y;
			bypass = bypass->next;
			buf_x = buf2_x;
			buf_y = buf2_y;
		}
		head1.tail->x = buf2_x;
		head1.tail->y = buf2_y;
		buf2_x = 0;
		buf2_x = 0;
		if (f->x == head1.new_x && f->y == head1.new_y) {
			eating_fruit(f);
		}
		snake_matrix[head1.new_x][head1.new_y].type = 1;
		head1.x = head1.new_x; 
		head1.y = head1.new_y;
	}
}

void Fields::eating_fruit(Fruit *f) {
	head1.score += f->score;
	if (f->growth == 1) {
		create(head1.next);
	}
	else if (f->growth == 2) {
		create(head1.next);
		create(head1.next);
	}
	f->life = 0;
	f->x = size;
	f->y = size;
}

void Fields::create(Body *&node) {
	if(node == NULL) {
		node = create_body();
	}
	else {
		create(node->next);
	}
}

Body* Fields::create_body() {
	int x, y, flag = 0;
	if (head1.tail->x < size -1) {
		if (snake_matrix[head1.tail->x + 1][head1.tail->y].type == 0 && flag == 0) {
			x = head1.tail->x + 1;
			y = head1.tail->y;
			flag = 1;
		}
	}
		if (snake_matrix[head1.tail->x - 1][head1.tail->y].type == 0 && flag == 0) {
		x = head1.tail->x - 1;
		y = head1.tail->y;
		flag = 1;
	}
	if (head1.tail->y < size - 1) {
		if (snake_matrix[head1.tail->x][head1.tail->y + 1].type == 0 && flag == 0) {
			x = head1.tail->x;
			y = head1.tail->y + 1;
			flag = 1;
		}
	}
		if (snake_matrix[head1.tail->x][head1.tail->y - 1].type == 0 && flag == 0) {
		x = head1.tail->x;
		y = head1.tail->y - 1;
		flag = 1;
	}
	if(flag == 1) {
		Body* body = new Body(x, y);
		head1.tail->x = x;
		head1.tail->y = y;
		return body;
	}
	return NULL;
}