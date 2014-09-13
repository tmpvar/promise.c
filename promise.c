#include <promise.h>
#include <stdlib.h>
#include <list.h>

typedef struct {
  void *userdata;
  promise_t *promise;
  promise_callback callback;
} callback_t;

promise_t *promise_new() {
  promise_t *ret = (promise_t *)malloc(sizeof(promise_t));
  ret->thens = list_new();
  ret->resolved = 0;
  return ret;
}

int promise_destroy(promise_t *promise) {
  list_destroy(promise->thens);
  free(promise);
  promise = 0;
  return 0;
}

void promise_resolve(promise_t *promise, void *value) {
  promise->value = value;
  list_iterator_t *it = list_iterator_new(promise->thens, LIST_HEAD);

  list_node_t *node;
  callback_t *p;
  while ((node = list_iterator_next(it))) {
    p = node->val;
    p->callback(promise, p->userdata, value);
  }

  list_iterator_destroy(it);

  promise->resolved = 1;
}

void promise_then(promise_t *source, void *userdata, promise_callback cb) {
  if (source->resolved) {
    cb(source, userdata, source->value);
  } else {
    callback_t *method = malloc(sizeof(callback_t));
    method->userdata = userdata;
    method->promise = source;
    method->callback = cb;
    list_rpush(source->thens, list_node_new(method));
  }
}

