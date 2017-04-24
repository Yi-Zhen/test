#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <iomanip>

using namespace std ;

class  Ruler {
  private :

    // �x�s��׶����U�q����
    vector<int>            lengths ;           
 
    // ���`�� 
    int                    total_length ;      

    // �x�s�Ҧ��i��`���ت��U�q����
    vector< vector<int> >  valid_lengths ;      

    // �ˬd�U��׶������׬O�_�������`���ةw�q
    bool  is_complete_ruler( const vector<int>& s ) const {
        
        bool  found  ;

        int  i , j , sum , n ;

        if ( s.size() == total_length ) return false ;
        
        for ( n = 1 ; n < total_length ; ++n ) {

            found = false ;
            for ( i = 0 ; i < s.size() ; ++i ) {

                sum = s[i] ;
                if ( sum != n ) {
                    for ( j = i+1 ; j < s.size() ; ++j ) {
                        sum += s[j] ;
                        if ( sum == n ) {
                            found = true ;
                            break ;
                        }
                    }
                } else {
                    found = true ;
                }

                if ( found ) break ;

            }
            if ( ! found ) return false ;
        }
        
        return  true ;
        
    }

    // �ˬd len �O�_���`����
    void  check_scales( vector<int> len ) {
        
        int  i , n = valid_lengths.size() ;
        bool  seen ;
        
        do {
            if ( is_complete_ruler(len) ) {

                seen = false ;
                for ( i = n ; i < valid_lengths.size() ; ++i ) {
                    if ( equal( valid_lengths[i].begin() , 
                                valid_lengths[i].end() , len.rbegin() ) ) {
                        seen = true ;
                        break ;
                    }
                }

                // �`���ت����׭Y�D�ϦV����, �h�x�s�_��
                if ( ! seen ) valid_lengths.push_back(len) ;

            }

        } while ( next_permutation(len.begin(),len.end()) ) ;
        
    }

    
    // ���j��M�C�q����
    void  find_lengths( int len , int depth ) {
        
        if ( depth == 1 ) {
            if ( len >= lengths.back() ) {
                lengths.push_back(len) ;
                check_scales( lengths ) ;
                lengths.pop_back() ;
            }
        } else {
            for ( int i = 1 ; i < len ; ++i ) {
                if ( lengths.size() == 0 || i >= lengths.back() ) {
                    lengths.push_back(i) ;
                    find_lengths(len-i,depth-1) ;
                    lengths.pop_back() ;
                }
            }
        }
    }
    
  public :
    
    Ruler( int len = 0 ) : total_length(len) {}

    // �]�w�`���ت���
    void  set_length( int len ) {
        total_length = len  ;
        lengths.resize(0) ;
        valid_lengths.resize(0) ;
    }
    
    // ��M�̤֨�ת��C�q����
    void  find_min_length() {

        for ( int d = 2 ; d < total_length ; ++d ) {

            find_lengths( total_length , d ) ;

            if ( valid_lengths.size() ) {
                for ( int i = 0 ; i < valid_lengths.size() ; ++i ) {
                    cout << "> " << setw(3) << i+1 << " : " ;
                    copy( valid_lengths[i].begin() , valid_lengths[i].end() ,
                          ostream_iterator<int>(cout," ") ) ;
                    cout << endl ;
                }
                return ;
            }
        }

    }
    
};


int main() {
    
    Ruler   ruler ;

    // �C�L���׬� 5 �� 10 �������̤֨�׸`���ت��U�q����
    for ( int i = 22 ; i < 23 ; ++i ) {
        cout << i << " : " << endl ;
        ruler.set_length(i) ;
        ruler.find_min_length() ;
        cout << endl ;
    }
    

    return 0 ;
}

