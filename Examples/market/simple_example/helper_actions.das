require jsonrpc
require items_storage_db

require base_entities
require market_utils



[jsonrpc_method(create_profile)]
def get_profile()
  send_result(persist)


[jsonrpc_method(admin_panel)]
def reinit_with_sample_items()
  clear(persist.items)
  var itemid <- generate_itemid()
  persist.items[itemid] <- [[Item item_type = "big_health_potion", id = itemid, count = 10u]]
  add_items_to_db([{uint64 item_id_to_uint64(itemid)}])
  send_result(persist)


[jsonrpc_method(admin_panel)]
def clear_transaction_history()
  clear(persist.transaction_history)
  send_result(persist)


[jsonrpc_method(admin_panel)]
def clear_items()
  clear(persist.items)
  send_result(persist)
