namespace strings {
   template <typename F>
   void split(char *s, char sp, F f) {
        char *p = s;
        while (*p) {
            char *q = strchr(p, sp);
            if (!q) {
                 f(p);
                 break;
            } else {
                char r = *q;
                *q = '\0';
                f(p);
                p = q + 1;
                *q = r;
            }
        }
   }
}
