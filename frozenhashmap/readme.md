# Frozen Hash Map
> simple frozen hashmap implementation

## Functions:
- `frozen_hash_map` - creates a new map
- `fh_lookup` - lookup function in the map
- `fh_insert` - inserts a new item into the map
- `fh_delete` - deletes an item from the map
- `free_fhm` - frees the map

## Structures:
- `HashBucket` - "private" bucket struct since non-frozen implementation wont use chaining
- `FrozenHashMap` - The FrozenHashMap struct