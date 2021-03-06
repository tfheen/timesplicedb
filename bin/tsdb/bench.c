/*
 * Copyright (c) 2009 Artur Bergman <sky@crucially.net>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "TSDB.h"
#include <sys/time.h>
#include <stdio.h>

int bench_usage() {
	WARN("no options\n");
}

int bench_main(int argc, char **argv) {
  struct timeval how_fast_start;
  struct timeval how_fast_stop;
    
/*
  struct NGR_metric_t *metric= NGR_create("host", "metric_c", time(NGR_NULL) - 3600, 1);

  return;
  //  struct NGR_metric_t *metric = NGR_open("host", "metric_year");
  printf("width: %d; created: %d\n", metric->width, metric->created);
  int idx = NGR_last_row_idx(metric);
  printf("row: %d\n", NGR_entry(metric,NGR_last_row_idx(metric),0));

  {

    struct NGR_range_t *range = NGR_range(metric, 0, idx);
    gettimeofday(&how_fast_start, NGR_NULL);
    int items = range->items;
    int i = 0;
    int total = 0;
    struct NGR_range_t *aggregate = NGR_aggregate(range, 86400,0);
    gettimeofday(&how_fast_stop, NGR_NULL);
    printf("Items:%d   Total: %d   Avg: %d\n", range->items, total, total/range->items);
    printf("%d.%d\n", how_fast_start.tv_sec, how_fast_start.tv_usec);
    printf("%d.%d\n", how_fast_stop.tv_sec, how_fast_stop.tv_usec);

    items = aggregate->items;
    i = 0;
    while(items--) {
      //      printf("AVG: %d      MAX: %d      MIN: %d      STDDEV: %d\n", aggregate->agg[i].avg, aggregate->agg[i].max, aggregate->agg[i].min, aggregate->agg[i].stddev);
      i++;
    }

    NGR_range_free(range);
  }
  {
    gettimeofday(&how_fast_start, NGR_NULL);
    struct NGR_range_t *range = NGR_timespan(metric, time(NGR_NULL)-36000, time(NGR_NULL)-35000);
    int items = range->items;
    int i = 0;
    while(items--) {
      int foo = range->row[i++];
      //      printf("%d\n", range->row[i++]);
    }
    gettimeofday(&how_fast_stop, NGR_NULL);
    printf("%d.%d\n", how_fast_start.tv_sec, how_fast_start.tv_usec);
    printf("%d.%d\n", how_fast_stop.tv_sec, how_fast_stop.tv_usec);
    printf("entries: %d\n", range->items);


    NGR_range_free(range);
  }
*/
  return 0;
}


