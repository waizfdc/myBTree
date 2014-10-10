#include "mydb.h"
#include <unistd.h>

int DB_btree_close(struct DB *db) {
	return 0;
}

int DB_btree_del(const struct DB *db, const struct DBT *key) {
	return 0;
}

int DB_btree_get(const struct DB *db, const struct DBT *key, struct DBT *data) {
	
}

int DB_btree_put(const struct DB *db, const struct DBT *key, const struct DBT *data) {

}

struct DB DB_btree = {
	DB_btree_close,
	DB_btree_del,
	DB_btree_get,
	DB_btree_put
};

int db_close(struct DB *db) {
	db->close(db);
}

int db_del(const struct DB *db, void *key, size_t key_len) {
	struct DBT keyt = {
		.data = key,
		.size = key_len
	};
	return db->del(db, &keyt);
}

int db_get(const struct DB *db, void *key, size_t key_len, void **val, size_t *val_len) {
	struct DBT keyt = {
		.data = key,
		.size = key_len
	};
	struct DBT valt = {0, 0};
	int rc = db->get(db, &keyt, &valt);
	*val = valt.data;
	*val_len = valt.size;
	return rc;
}

int db_put(const struct DB *db, void *key, size_t key_len, void *val, size_t val_len) {
	struct DBT keyt = {
		.data = key,
		.size = key_len
	};
	struct DBT valt = {
		.data = val,
		.size = val_len
	};
	return db->put(db, &keyt, &valt);
}

