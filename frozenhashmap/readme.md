# Frozen Hash Map
> simple frozen hashmap implementation

implements 4 simple hashmap functions:
- `FrozenHashMap *frozen_hash_map(unsigned int);`
- `HashEntry *fh_lookup(FrozenHashMap *, char *);`
- `void fh_insert(FrozenHashMap *, char *, void *);`
- `void fh_delete(FrozenHashMap *, char *);`
- `void free_fhm(FrozenHashMap *);`
