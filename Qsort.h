#ifndef QSORT_H_INCLUDED
#define QSORT_H_INCLUDED

size_t my_qsort(struct line* lines, size_t left, size_t right,
                int (*comp)(const struct line*, const struct line*));

void swap(struct line* lines, size_t left, size_t right);

size_t partition(struct line* lines, size_t left, size_t right,
                 int (*comp)(const struct line*, const struct line*));

int str_compare_lr(const struct line* line1, const struct line* line2);

int str_compare_rl(const struct line* line1, const struct line* line2);

#endif // QSORT_H_INCLUDED
