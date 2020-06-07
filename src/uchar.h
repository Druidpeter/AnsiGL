#ifndef __ANSIGL_UCHAR_H__
#define __ANSIGL_UCHAR_H__

/*
 * uchar.h
 *
 * The AnsiGL UTF-8 "char"...always represents a single glyph.
 */


#include <cctype>
#include <ostream>
#include <string>


namespace AnsiGL
{
  //
  // Forward declaration of achar so we can convert both ways
  //
  class achar;


  //! @class uchar
  //! @brief An encapsulation of a unicode character.
  //! A UTF-8 'char' always of the same physical width(1) regardless of the
  //! width of its glyph.
  
  class uchar{
  protected:
    std::string	_UTF8;
  public:
    uchar &operator=( const achar &right );
    uchar &operator=( const std::string &right );
    uchar &operator=( const unsigned char &right );

    bool operator==( const uchar &right ) const;
    bool operator!=( const uchar &right ) const;
    bool operator==( const achar &right ) const;		// Compares only the glyphs
    bool operator!=( const achar &right ) const;
    bool operator==( const std::string &right ) const;	// Compares the std::string as a single unicode glyph
    bool operator!=( const std::string &right ) const;
    bool operator==( const unsigned char &right ) const;
    bool operator!=( const unsigned char &right ) const;

    void Glyph( const uchar &glyph );
    void Glyph( const achar &glyph );
    void Glyph( const std::string &glyph );
    void Glyph( unsigned char glyph );
    
    uchar():
      _UTF8(" "){}

    uchar( const achar &glyph );

    uchar( const std::string &glyph ){
      Glyph( glyph );
    }

    uchar( unsigned char glyph ){
      if ( glyph < 128 )
        (*this) = glyph;
    }

    char &operator<<( const achar &right ){
      return ((*this) = right);
    }

    uchar &operator<<( const std::string &right ){
      return ((*this) = right);
    }

    uchar &operator<<( const unsigned char &right ){
      return ((*this) = right);
    }

    const std::string &Glyph() const{
      return _UTF8;
    }

    //! Returns 'true' if the glyph is whitespace
    bool IsSpace() const{
      return (_UTF8.empty() || isspace(*_UTF8.begin()));
    }

    void Clear(){
      _UTF8 = " ";
    }

    //! Simply returns the glyph.
    const std::string &Render() const{
      return _UTF8;
    }
  };


  extern std::ostream &operator<<( std::ostream &left, const uchar &right );
}


#endif // __ANSIGL_UCHAR_H__


// vim: tabstop=4 shiftwidth=4
// astyle: --indent=tab=4 --style=ansi --indent-namespaces --indent-cases --indent-switches --pad-oper


