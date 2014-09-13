#include <promise.h>
#include <assert.h>
#include <stdio.h>


uint8_t b_resolve_count = 0;
int b_resolve(promise_t *promise, void *userdata, void *value) {
  b_resolve_count++;
  return 1;
}

int main() {

  promise_t *a = promise_new();
  assert(promise_destroy(a) == 0);

  promise_t *b = promise_new();

  promise_then(b, 0, b_resolve);

  promise_resolve(b, "test");
  assert(b_resolve_count == 1);

  promise_then(b, 0, b_resolve);
  assert(b_resolve_count == 2);

  return 0;
}
