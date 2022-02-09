const char* json = "{\"ok\":true,\"result\":{\"id\":5026986092,\"is_bot\":true,\"first_name\":\"Jalu\",\"username\":\"MangJalu_bot\",\"can_join_groups\":true,\"can_read_all_group_messages\":false,\"supports_inline_queries\":false}}";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  char val[20];

  getValue(json, "id", val);
  Serial.println(val);
  getValue(json, "first_name", val);
  Serial.println(val);
  delay(1000);
}

void getValue(const char *src, const char* key,  char*val)
{
  char *firstIndex;
  char *lastIndex;
  int len;

  firstIndex = strstr(src, key) + strlen(key) + 2;
  lastIndex = strstr(firstIndex, ",");

  if (*firstIndex == '\"') firstIndex++;
  if (*(lastIndex-1) == '\"') lastIndex--;
  
  len = lastIndex - firstIndex;

  strncpy(val, firstIndex, len);
  val[len] = 0;
}
