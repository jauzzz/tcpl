#include <stdio.h>

#define XMAX 100
#define YMAX 100

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
};

int main()
{
    struct rect screen;
    struct point middle;
    struct point makepoint(int, int);
    struct point addpoint(struct point, struct point);
    int ptinrect(struct point, struct rect);
    struct rect canonrect(struct rect);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(XMAX, YMAX);
    middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                       (screen.pt1.y + screen.pt2.y) / 2);

    printf("middle.x: %d\n", middle.x);
    printf("middle.y: %d\n", middle.y);

    struct point p1 = {5, 5};
    p1 = addpoint(p1, middle);
    printf("---------------\n");
    printf("p1.x: %d\n", p1.x);
    printf("p1.y: %d\n", p1.y);

    int p1inscreen = ptinrect(p1, screen);
    printf("---------------\n");
    printf("p1 in screen: %d\n", p1inscreen);

    struct point p2;
    printf("---------------\n");
    printf("p2.x: %d\n", p2.x);
    printf("p2.y: %d\n", p2.y);

    struct rect r1 = {10, 10, 0, 0};
    printf("---------------\n");
    printf("r1.pt1.x: %d\n", r1.pt1.x);
    printf("r1.pt1.y: %d\n", r1.pt1.y);
    printf("r1.pt2.x: %d\n", r1.pt2.x);
    printf("r1.pt2.y: %d\n", r1.pt2.y);

    r1 = canonrect(r1);
    printf("\n");
    printf("canonrect:\n");
    printf("r1.pt1.x: %d\n", r1.pt1.x);
    printf("r1.pt1.y: %d\n", r1.pt1.y);
    printf("r1.pt2.x: %d\n", r1.pt2.x);
    printf("r1.pt2.y: %d\n", r1.pt2.y);
    printf("---------------\n");

    struct rect r2 = {{20, 0}, {0, 20}};
    printf("r2.pt1.x: %d\n", r2.pt1.x);
    printf("r2.pt1.y: %d\n", r2.pt1.y);
    printf("r2.pt2.x: %d\n", r2.pt2.x);
    printf("r2.pt2.y: %d\n", r2.pt2.y);

    r2 = canonrect(r2);
    printf("\n");
    printf("canonrect:\n");
    printf("r2.pt1.x: %d\n", r2.pt1.x);
    printf("r2.pt1.y: %d\n", r2.pt1.y);
    printf("r2.pt2.x: %d\n", r2.pt2.x);
    printf("r2.pt2.y: %d\n", r2.pt2.y);
    printf("---------------\n");

    struct point origin = {15, 20};
    struct point *pp;
    pp = &origin;
    printf("origin is (%d,%d)\n", (*pp).x, (*pp).y);
    printf("origin is (%d,%d)\n", pp->x, pp->y);

    return 0;
}

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
    struct point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

struct point addpoint(struct point p1, struct point p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}

/* ptinrect: return 1 if p in r, 0 if not */
int ptinrect(struct point p, struct rect r)
{
    return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}

/* canonrect: canonicalize coordinates of rectangle */
struct rect canonrect(struct rect r)
{
    struct rect temp;

    temp.pt1.x = min(r.pt1.x, r.pt2.x);
    temp.pt1.y = min(r.pt1.y, r.pt2.y);
    temp.pt2.x = max(r.pt1.x, r.pt2.x);
    temp.pt2.y = max(r.pt1.y, r.pt2.y);
    return temp;
}