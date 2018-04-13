# Maintainer: David "JohnBobSmith" Bogner <myrunescapeemail609 AT gmail DOT com>
pkgname=attackoftheasteroids-git
__pkgname=attackoftheasteroids
pkgver=r28.74b901f
pkgrel=1
pkgdesc="A.O.T.A - A simple 2D shooting and defense game."
arch=(x86_64)
depends=('sfml')
makedepends=('git')
url="https://github.com/JohnBobSmith/attackoftheasteroids"
license=('MIT')
source=("git+https://github.com/JohnBobSmith/attackoftheasteroids.git")
md5sums=('SKIP')

pkgver() {
  cd "$_pkgname"
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd "$_pkgname/"
	make
}

package() {
	cd "$_pkgname"
	make DESTDIR="$pkgdir/" install
}
