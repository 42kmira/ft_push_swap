/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ran_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:26:08 by kmira             #+#    #+#             */
/*   Updated: 2020/02/03 23:57:24 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** Make a sorted list first then randomly generate the location.
** for the location you can keep skipping values until you find an
** empty bucket. This would avoid you from having to check if the
** number is unique and continue rerolling until you find a unique
** number.
*/

#define EMPTY -1

int		*make_random_list(int size)
{
	int		i;
	int		j;
	int		rand_loc;
	int		*sorted;
	int		*result;

	i = 0;
	result = malloc(sizeof(*result) * (size + 1));
	sorted = malloc(sizeof(*sorted) * (size + 1));
	while (i < size)
	{
		sorted[i] = i + 1;
		result[i] = EMPTY;
		i++;
	}

	i = 0;
	while (i < size)
	{
		j = 0;
		rand_loc = rand() % size;
		while (result[rand_loc + j] != EMPTY)
		{
			j++;
			if (rand_loc + j == size)
			{
				j = 0;
				rand_loc = 0;
			}
		}
		result[rand_loc + j] = sorted[i];
		i++;
	}
	return (result);
}

void	print_out_list(int size)
{
	int	i;
	int	*result;

	i = 0;
	result = make_random_list(size);
	while (i < size)
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");
}

int		main(int aa, char **args)
{
	int	i;
	int	size;

	// char *tree_size = malloc(5500 * 11 * (500 * 4));

	// if (tree_size == NULL)
		// printf("ENOMEM\n");
	srand(time(NULL));
	if (aa == 2)
	{
		i = 0;
		size = atoi(args[1]);
		while (i < 1)
		{
			print_out_list(size);
			i++;
		}
	}
	else
		printf("Wrong number of arguements\n");
	return (0);
}


// system("./push_swap 302 222 243 24 245 415 19 263 307 143 312 166 194 205 228 231 371 278 373 413 423 424 297 212 425 279 432 364 7 110 393 434 436 437 441 445 209 28 124 151 18 172 17 125 261 173 289 332 422 112 137 150 214 306 314 368 400 174 2 420 447 450 452 455 456 464 465 145 375 467 468 92 23 50 86 97 202 221 31 189 9 53 191 75 246 264 333 182 349 256 269 392 402 440 411 274 458 395 461 235 217 290 396 417 463 470 354 471 37 472 473 474 476 478 71 480 481 5 363 211 74 171 227 210 193 252 106 353 57 206 338 38 181 105 3 80 146 160 192 87 237 258 56 284 165 291 322 381 388 60 398 78 259 399 403 68 219 12 100 158 426 428 241 152 318 389 118 127 431 121 366 439 304 444 446 374 128 215 10 198 317 22 230 294 154 99 345 370 30 286 382 433 59 459 466 475 479 430 8 48 157 175 179 185 412 311 448 161 54 104 170 335 457 236 482 298 62 301 427 483 484 485 488 469 489 44 61 138 178 216 42 262 275 34 323 103 153 51 45 94 342 347 109 348 377 76 319 397 190 69 435 55 177 183 443 451 453 454 460 462 490 52 492 188 64 200 195 283 404 362 176 229 408 491 249 380 438 26 73 77 117 351 184 20 21 141 325 123 131 372 85 140 187 418 486 493 43 240 409 139 208 225 341 40 82 204 213 343 282 196 344 356 98 406 449 149 224 487 494 495 35 496 390 39 477 497 223 442 498 499 148 201 361 384 500 360 167 234 266 16 93 25 46 41 66 70 116 120 142 156 186 13 197 102 280 251 292 90 242 239 308 58 135 276 287 288 309 320 330 63 331 340 250 83 355 15 232 134 260 164 296 79 357 168 359 273 379 81 270 383 387 407 414 416 220 89 203 346 334 272 281 155 72 419 421 429 130 133 265 271 4 1 65 268 277 300 126 163 316 101 324 226 113 169 96 29 144 328 337 339 233 352 358 14 129 367 49 267 321 67 88 305 326 327 376 199 36 33 32 132 162 238 6 218 244 84 254 299 350 114 365 378 386 257 11 122 207 248 336 394 401 405 159 285 369 313 27 293 91 253 255 119 147 95 111 115 180 247 295 310 107 108 315 136 329 47 385 303 391 410");
