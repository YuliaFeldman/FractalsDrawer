#ifndef EX2_FRACTAL_H
#define EX2_FRACTAL_H

/**
 *
 */
class Fractal
{
protected:

	int _dim;

public:

	/**
	 * Draws fractal
	 */
	virtual void draw() = 0;

	/**
	 * Distructor
	 */
	virtual ~Fractal() = default;

	/**
	 * Constructor
	 * @param dim the dimension of fractal
	 */
	Fractal(const int &dim): _dim(dim) {}

	/**
	 * Copy constructor
	 * @param other another fractal
	 */
	Fractal(const Fractal& other) = default;

	/**
	 * Move constructor
	 * @param other another fractal
	 */
	Fractal(Fractal && other) = default;

	/**
	 * Operator '='
	 * @param other fractal
	 * @return this fractal
	 */
	Fractal& operator=(const Fractal& other) = default;

	/**
	 * Move operator '='
	 * @param other another fractal
	 * @return this fractal
	 */
	Fractal& operator=(Fractal && other) = default;
};



/**
 * Sierpinski Carpet Fractal
 */
class SierpinskiCarpet: public Fractal
{
public:

	/**
	 * Constructor
	 * @param dim the dimension of Sierpinski Carpet fractal
	 */
	SierpinskiCarpet(const int &dim): Fractal(dim) {}

	/**
	 * Destructor
	 */
	~SierpinskiCarpet() {}

	/**
     * Draws Sierpinski Carpet fractal
     */
	void draw() override;

	/**
	 * Copy constructor
	 * @param other another Sierpinski Carpet fractal
	 */
	SierpinskiCarpet(const SierpinskiCarpet &other) = default;

	/**
	 * Move constructor
	 * @param other another Sierpinski Carpet fractal
	 */
	SierpinskiCarpet(SierpinskiCarpet && other) = default;

	/**
	 * Operator '='
	 * @param other another Sierpinski Carpet fractal
	 * @return this fractal
	 */
	SierpinskiCarpet& operator=(const SierpinskiCarpet &other) = default;

	/**
	 * Move operator '='
	 * @param other another Sierpinski Carpet fractal
	 * @return this fractal
	 */
	SierpinskiCarpet& operator=(SierpinskiCarpet && other) = default;

private:

	bool _helperFunc(long x, long y);
};


/**
 * Sierpinski Sieve Fractal
 */
class SierpinskiSieve: public Fractal
{
public:

	/**
	 * Constructor
	 * @param dim the dimension of Sierpinski Sieve fractal
	 */
	SierpinskiSieve(const int &dim): Fractal(dim) {}

	/**
	 * Destructor
	 */
	~SierpinskiSieve() {}

	/**
     * Draws Sierpinski Sieve fractal
     */
	void draw() override;

	/**
	 * Copy constructor
	 * @param other another Sierpinski Sieve fractal
	 */
	SierpinskiSieve(const SierpinskiSieve &other) = default;

	/**
	 * Move constructor
	 * @param other another Sierpinski Sieve fractal
	 */
	SierpinskiSieve(SierpinskiSieve && other) = default;

	/**
	 * Operator '='
	 * @param other another Sierpinski Sieve fractal
	 * @return this fractal
	 */
	SierpinskiSieve& operator=(const SierpinskiSieve &other) = default;

	/**
	 * Move operator '='
	 * @param other another Sierpinski Sieve fractal
	 * @return this fractal
	 */
	SierpinskiSieve& operator=(SierpinskiSieve && other) = default;
};

/**
 * Cantor Dust Fractal
 */
class CantorDust: public Fractal
{
public:
	/**
	 * Constructor
	 * @param dim the dimension of Cantor Dust fractal
	 */
	CantorDust(const int &dim): Fractal(dim) {}

	/**
	 * Destructor
	 */
	~CantorDust() {}

	/**
     * Draws Cantor Dust fractal
     */
	void draw() override;

	/**
	 * Copy constructor
	 * @param other another Cantor Dust fractal
	 */
	CantorDust(const CantorDust &other) = default;

	/**
	 * Move constructor
	 * @param other another Cantor Dust fractal
	 */
	CantorDust(CantorDust && other) = default;

	/**
	 * Operator '='
	 * @param other another Cantor Dust fractal
	 * @return this fractal
	 */
	CantorDust& operator=(const CantorDust &other) = default;

	/**
	 * Move operator '='
	 * @param other another Cantor Duste fractal
	 * @return this fractal
	 */
	CantorDust& operator=(CantorDust && other) = default;

private:
	void _helperFunc(long x, long y);

};


#endif //EX2_FRACTAL_H
