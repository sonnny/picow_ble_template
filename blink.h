// blink.h

void bt_main(void);
struct bt_type{
  uint8_t data;
};

void bt_get_latest(struct bt_type *dst);
