#include <stdlib.h>
#include <check.h>

#include "modex.h"

void array_match_test(char *array, unsigned int array_len, mx_slist_t *slist)
{
    for(unsigned int i = 0; i < array_len; i++, slist = slist->next)
        fail_unless(*(char*)slist->data == array[i], "slist does not match array");
}

START_TEST (test_slist_0000)
{ 
    mx_slist_t *l = NULL;
    char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';
    char x[5] = { 'E', 'D', 'C', 'B', 'A' };

    l = mx_slist_insert(l, &a);  
    l = mx_slist_insert(l, &b);
    l = mx_slist_insert(l, &c);
    l = mx_slist_insert(l, &d);
    l = mx_slist_insert(l, &e);

    array_match_test(x, 5, l);
}
END_TEST

START_TEST (test_slist_0001)
{ 
    mx_slist_t *l = NULL;
    char a = 'A', b = 'B', c = 'C', d = 'D', e = 'E';
    char x[5] = { 'A', 'B', 'C', 'D', 'E' };

    l = mx_slist_insert_end(l, &a);  
    l = mx_slist_insert_end(l, &b);
    l = mx_slist_insert_end(l, &c);
    l = mx_slist_insert_end(l, &d);
    l = mx_slist_insert_end(l, &e);

    array_match_test(x, 5, l);
}
END_TEST


Suite* slist_suite(void)
{
    Suite *s = suite_create("slist");
    TCase *tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_slist_0000);
    tcase_add_test(tc_core, test_slist_0001);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int fail_count;
    Suite *s = slist_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);

    fail_count = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (fail_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
