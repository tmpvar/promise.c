#ifndef __PROMISE_H__
#define __PROMISE_H__

#include <inttypes.h>
#include <list.h>

typedef struct {
  uint8_t resolved;
  void *value;

  list_t *thens;
} promise_t;

typedef int (*promise_callback)(promise_t *promise, void *userdata, void *value);

promise_t *promise_new();
int promise_destroy(promise_t *promise);

void promise_resolve(promise_t *promise, void *value);
void promise_then(promise_t *source, void *userdata, promise_callback cb);

#endif
