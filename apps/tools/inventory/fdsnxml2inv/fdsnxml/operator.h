/***************************************************************************
 * Copyright (C) gempa GmbH                                                *
 * Contact: gempa GmbH (seiscomp-dev@gempa.de)                             *
 *                                                                         *
 * This file may be used under the terms of the GNU Affero                 *
 * Public License version 3.0 as published by the Free Software Foundation *
 * and appearing in the file LICENSE included in the packaging of this     *
 * file. Please review the following information to ensure the GNU Affero  *
 * Public License version 3.0 requirements will be met:                    *
 * https://www.gnu.org/licenses/agpl-3.0.html.                             *
 ***************************************************************************/


#ifndef SEISCOMP_FDSNXML_OPERATOR_H
#define SEISCOMP_FDSNXML_OPERATOR_H


#include <fdsnxml/metadata.h>
#include <fdsnxml/agency.h>
#include <fdsnxml/stringtype.h>
#include <vector>
#include <seiscomp/core/baseobject.h>
#include <seiscomp/core/exceptions.h>


namespace Seiscomp {
namespace FDSNXML {

DEFINE_SMARTPOINTER(Person);



DEFINE_SMARTPOINTER(Operator);


/**
 * \brief An operating agency and associated contact persons. If there
 * \brief multiple operators, each one should be encapsulated within an
 * \brief Operator tag. Since the Contact element is a generic type that
 * \brief represents any contact person, it also has its own optional Agency
 * \brief element.
 */
class Operator : public Core::BaseObject {
	DECLARE_CASTS(Operator);
	DECLARE_RTTI;
	DECLARE_METAOBJECT_DERIVED;

	// ------------------------------------------------------------------
	//  Xstruction
	// ------------------------------------------------------------------
	public:
		//! Constructor
		Operator();

		//! Copy constructor
		Operator(const Operator &other);

		//! Destructor
		~Operator();


	// ------------------------------------------------------------------
	//  Operators
	// ------------------------------------------------------------------
	public:
		//! Copies the metadata of other to this
		Operator& operator=(const Operator &other);
		bool operator==(const Operator &other) const;


	// ------------------------------------------------------------------
	//  Setters/Getters
	// ------------------------------------------------------------------
	public:
		//! XML tag: Agency
		void setAgency(const Agency& agency);
		Agency& agency();
		Agency agency() const;

		//! XML tag: WebSite
		void setWebSite(const OPT(StringType)& webSite);
		StringType& webSite();
		const StringType& webSite() const;

	
	// ------------------------------------------------------------------
	//  Public interface
	// ------------------------------------------------------------------
	public:
		/**
		 * Add an object.
		 * @param obj The object pointer
		 * @return true The object has been added
		 * @return false The object has not been added
		 *               because it already exists in the list
		 *               or it already has another parent
		 */
		bool addContact(Person *obj);

		/**
		 * Removes an object.
		 * @param obj The object pointer
		 * @return true The object has been removed
		 * @return false The object has not been removed
		 *               because it does not exist in the list
		 */
		bool removeContact(Person *obj);

		/**
		 * Removes an object of a particular class.
		 * @param i The object index
		 * @return true The object has been removed
		 * @return false The index is out of bounds
		 */
		bool removeContact(size_t i);

		//! Retrieve the number of objects of a particular class
		size_t contactCount() const;

		//! Index access
		//! @return The object at index i
		Person* contact(size_t i) const;


	// ------------------------------------------------------------------
	//  Implementation
	// ------------------------------------------------------------------
	private:
		// Attributes
		Agency _agency;
		OPT(StringType) _webSite;

		// Aggregations
		std::vector<PersonPtr> _contacts;
};


}
}


#endif
