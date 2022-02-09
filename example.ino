String json = "{\"ok\":true,\"result\":{\"id\":5026986092,\"is_bot\":true,\"first_name\":\"Jalu\",\"username\":\"MangJalu_bot\",\"can_join_groups\":true,\"can_read_all_group_messages\":false,\"supports_inline_queries\":false}}";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  String s;
  s = getValue(&json, "id");
  Serial.println(s);
  s = getValue(&json, "first_name");
  Serial.println(s);
  delay(1000);
}

String getValue(String *scr, const char* key)
{
  int firstIndex = scr->indexOf(key);
  int lastIndex = scr->indexOf(",", firstIndex);
  firstIndex += strlen(par) + 2;

  if (scr->charAt(firstIndex) == '\"') firstIndex++;
  if (scr->charAt(lastIndex - 1) == '\"') lastIndex--;

  String ret = scr->substring(firstIndex, lastIndex);
  return ret;
}
