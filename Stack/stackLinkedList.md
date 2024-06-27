Stack (stack.top)
+------+
|      | ----> +------+    +------+    +------+    +------+    +------+
| top  |       | data |    | data |    | data |    | data |    | data |
|      |       |  50  |    |  40  |    |  30  |    |  20  |    |  10  |
|      |       +------+    +------+    +------+    +------+    +------+
+------+
             next|          next|          next|          next|          next|
                 v              v              v              v              v
               NULL           NULL           NULL           NULL           NULL



Final step after poping
Stack (stack.top)
+------+
|      | ----> +------+    +------+    +------+
| top  |       | data |    | data |    | data |
|      |       |  30  |    |  20  |    |  10  |
|      |       +------+    +------+    +------+
+------+
             next|          next|          next|
                 v              v              v
               NULL           NULL           NULL
